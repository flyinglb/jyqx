//prison.c ��Ѻĳ��
// Byp@MX

inherit F_CLEAN_UP;
#define MAX_P_TIME 24*60
void do_release(object me);

int main(object me, string arg)
{
        object who;
        int ptime;
        if(!wizardp(me))
                return notify_fail("�����ʲô��\n");
        if(!arg)
                return notify_fail("���˭��\n");
        if( sscanf(arg, "%s %d", arg, ptime)!=2 )
                ptime = 60;
        
        who = find_player(arg);
        
        if(!who) 
                return notify_fail("û�������ҡ�\n");
                
        if(wizardp(who)) 
                return notify_fail("���ܹ���ʦ��\n");

//        if(!who->query_temp("warrning")) 
//                return notify_fail("��Ҫ�����ɱ�������� warning ��������ɡ�\n")

        if(ptime > MAX_P_TIME)
                return notify_fail("����ҳͷ��벻Ҫ����������\n");
        
        seteuid(getuid());
        who->move("/d/wizard/prison");
        who->set("prison/start_time", time());
        who->set("prison/release_time", ptime);
        who->set("startroom",base_name(environment(who)));
        who->save();
        who->disable_player(HIR"<��Ѻ��>"NOR);

        CHANNEL_D->do_channel(this_object(), "rumor", "��˵"
        + who->name() + "��Ϊ���ұ��ؽ��˽�ӹ������\n");
        
        who->set_temp("block_msg/all", 1);
        call_out("do_release",60, who);
        return 1;
}

void do_release(object who)
{
        if(!objectp(who)) return;
        if((int)who->query("prison/release_time") > 0) {
                who->add("prison/release_time", -1);
                //���������Ϊϵͳ���Զ� enable_player()
                who->disable_player(HIR"<��Ѻ��>"NOR);
                who->save();
                call_out("do_release",60, who);
                return;
        }
        who->enable_player();
        who->set_temp("block_msg/all",0);
        who->delete("prison");
        who->move("/d/city/wumiao");
        who->set("startroom","/d/city/wumiao");
        message("vision", "���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������\n"
                "�ܾ��ˣ�ֻ����һֱû������\n", environment(who), who);
        tell_object(who, 
        HIG"MUD �Ǵ���������еĵط�����Ҫ���ҵĹ�ͬά����ذ�����������ҹ���\n"
        HIR"�����������㱻�ͷ��ˣ�\n"NOR);
        return ;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : prison <ID> [<time>]
 
���������ͷ���Щ���ҵ���ң������ǹ�Ѻ�����Ρ�
ʱ��ĵ�λΪ���ӣ����û�� time ѡ����Ĭ�Ϲ�Ѻ
һСʱ�����û�г�������벻Ҫʹ�ô����
HELP
    );
    return 1;
}
