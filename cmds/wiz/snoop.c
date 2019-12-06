// snoop.c
// Modify By Byp@MX 

inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
        object who;
        string flag, id;
        
        if( !arg ) {
                if( objectp(who = query_snooping(me)) ) {
                        write("���������ڼ���" + who->query("name") + "���յ���ѶϢ��\n");
                        return 1;
                } else return help();
        } else if( arg=="none" ) {
//                      if( objectp(who = query_snooping(me))
//                      && wiz_level(who) >= wiz_level(me) )
//                      tell_object(who, HIW + me->name(1) + "ֹͣ���������յ���ѶϢ��\n" NOR);
                        snoop(me);
                        write("Ok.\n");
                        return 1;
        } else if( sscanf(arg,"%s %s", flag, id) != 2 ){
                who = find_player(arg);
                if(!who) who = find_living(arg);
                if(!who || !me->visible(who)) return notify_fail("û������ˡ�\n");

                if( wiz_level(me) <= wiz_level(who) )
                        return notify_fail("��û�м���" + who->name() + "ѶϢ��Ȩ����\n");

                if( me == who ) return notify_fail("���� snoop none ���������\n");
                
                snoop(me, who);
                write("�����ڿ�ʼ����" + who->name(1) + "���յ���ѶϢ��\n");
                if( userp(who) ) log_file("SNOOP_PLAYER",
                        sprintf("%s(%s) snoops %s on %s.\n", me->name(1), geteuid(me), who->name(1),
                                ctime(time()) ) );
//              if( wizardp(who) && wizhood(me) != "(admin)")
//                      tell_object(who, HIW + me->name(1) + "��ʼ���������յ���ѶϢ��\n" + NOR);

                return 1;
        }
        
        who = find_player(id);
        if(!who) who = find_living(id);
        if( (!who || !me->visible(who)) && id != "all") return notify_fail("û�������....��\n");
        
        switch(flag) {
                case "add" : 
                        if(id == "all") {
                                users()->set("channel_snooping",1);
                                write("��ʼ�������������û���\n");
                        } else {
                                who->set("channel_snooping",1);
                                write("��ʼ����"+who->name()+"\n");
                        }
                        break;
                case "del" : 
                        if(id == "all") {
                                users()->delete("channel_snooping",1);
                                write("ȡ���������������û���\n");
                        } else {
                                who->delete("channel_snooping");
                                write("ȡ������"+who->name()+"\n");
                        }
                        break;
                default : 
                        return help();
                        break;
        }
        return 1;
}

int help()
{
        write(@TEXT
ָ���ʽ(1)��snoop <add | del> <USER ID | all>
ָ���ʽ(2)��snoop <USER ID | none>

��һ��ָ���ʽ�Ǵ򿪻�رռ���ĳ�˵Ľ�̸��Ϣ��
�� user id Ϊ all ��ʱ����ָ���������û���

�ڶ���ָ���ʽ�Ǵ򿪻�رյ�������ĳ�˵�������Ϣ��
TEXT
        );
        return 1;
}
