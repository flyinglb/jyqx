// yirong.c
// by mon. 1/3/97

#include <ansi.h>

int do_yirong(object me);

int main(object me, string arg)
{
//        string id;
//        object who,obj;
        object who;
        int jingli,yirongshu,djingli;

        seteuid(getuid());

        if( me->is_fighting() )
                return notify_fail("������ս������Ͼ���ݡ�\n");
        if( me->is_busy() || me->query_temp("pending/exercising"))
                return notify_fail("����æ���أ�û�������ݡ�\n");
        if( (int)me->query_skill("yirongshu") < 1 )
                return notify_fail("���������������ᣬ�ͱ���������?\n");

        if (!arg || arg=="me" || arg==me->query("id")) 
                who=me;
        else {
                if(!objectp(who=present(arg,environment(me)))) 
                        return notify_fail("�������ݳ�˭��\n");
        }

        if(who==me) {
                me->delete_temp("yirongshulevel");
                me->delete_temp("apply/name");
                me->delete_temp("apply/id");
                me->delete_temp("apply/short");
                me->delete_temp("apply/long");
                if(me->query_temp("d_jingli")) {
                        me->delete_temp("d_jingli");
                        while( environment(me)->is_character() )
                                me->move(environment(environment(me)));
             
                        message_vision(HIY "$N�ÿ鲼������һĨ��ת��֮��ָ��˱�����ò��\n"NOR,me);
                } else {
                        return notify_fail("�������ݳ�˭��\n");
                }
        } else {
                yirongshu=me->query_skill("yirongshu");
                jingli=me->query("jingli");
                if (me->query("combat_exp") < 300) 
                        return notify_fail("��ľ��黹������\n");
                if (yirongshu<25)
                        return notify_fail("��Ļ�����������ûѧ���ҡ�\n");
                if (jingli<50)
                        return notify_fail("��ľ������㡣\n");
                //if (wizardp(who) && !wizardp(me))
                if (wizardp(who))
                        return notify_fail("���޷����ݳ���ʦ��\n");
        
                djingli=15+400/(jingli-20); 
        
                message_vision(HIY "$N�������ҳ�һЩ���ص�ҩ������������࣬������һ����ͼ����ú�$nһģһ��,��������ѷ֣�\n" NOR,me,who);
                me->set_temp("yirongshulevel",yirongshu);
                me->set_temp("apply/name",({who->name()}));
                me->set_temp("apply/id",who->parse_command_id_list());
                me->set_temp("apply/short", ({who->short()}));
                me->set_temp("apply/long", ({who->long()}));
                me->add("jingli",-50);
                me->set_temp("is_character",who->is_character());
                me->set_temp("is_living",living(who));
                me->set_temp("gender",who->query("gender"));
                me->set_temp("age",who->query("age"));
                me->set_temp("race",who->query("race"));
                me->set_temp("family",who->query("family"));
                me->set_temp("unit",who->query("unit"));

                if (!me->query_temp("d_jingli")) call_out("do_yirong",5,me);
                        me->set_temp("d_jingli",djingli);
      }

      return 1;
}

int do_yirong(object me)
{  
        int djingli,jingli,yirongshu;

        if(!me) return 1;

        djingli=me->query_temp("d_jingli");
        yirongshu=me->query_temp("yirongshulevel");
   
//    tell_object(me,"jingli, d_jingli, yirongshu:"+me->query("jingli")+
//     ","+djingli+","+yirongshu+"\n");

        jingli=me->query("jingli");
        if ((jingli-djingli)>50 && yirongshu>0 && djingli>0) {
                me->add("jingli",(-djingli));
                call_out("do_yirong",5,me);
        } else {
                jingli=jingli-djingli;
                if (jingli<1) jingli=1;
                me->set("jingli",jingli);
                me->delete_temp("yirongshulevel");
                me->delete_temp("d_jingli");
                me->delete_temp("apply/name");
                me->delete_temp("apply/id");
                me->delete_temp("apply/short");
                me->delete_temp("apply/long");
                while( environment(me)->is_character() )
                        me->move(environment(environment(me)));
                if (djingli>0) 
                        message_vision(HIY"ֻ��$N�����ϵ�ҩ���ȥ���ָ��˱�����ò��\n" NOR,me);
    }

    return 1;
}

int help(object me)
{
        write(@HELP

ָ���ʽ �� yirong [<����>|<NPC>|<me>]

�����������ָ���������ݳ����������ģ�����Ƿ������ݣ���Ҫȡ����
�����������Ϊ�;�����С��

���ָ� shipo
HELP
        );
        return 1;
}




