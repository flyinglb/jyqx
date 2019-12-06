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
                return notify_fail("你正在战斗，无暇易容。\n");
        if( me->is_busy() || me->query_temp("pending/exercising"))
                return notify_fail("你正忙着呢，没工夫易容。\n");
        if( (int)me->query_skill("yirongshu") < 1 )
                return notify_fail("你连易容术都不会，就别提易容了?\n");

        if (!arg || arg=="me" || arg==me->query("id")) 
                who=me;
        else {
                if(!objectp(who=present(arg,environment(me)))) 
                        return notify_fail("你想易容成谁？\n");
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
             
                        message_vision(HIY "$N用块布朝脸上一抹，转眼之间恢复了本来面貌。\n"NOR,me);
                } else {
                        return notify_fail("你想易容成谁？\n");
                }
        } else {
                yirongshu=me->query_skill("yirongshu");
                jingli=me->query("jingli");
                if (me->query("combat_exp") < 300) 
                        return notify_fail("你的经验还不够。\n");
                if (yirongshu<25)
                        return notify_fail("你的基本易容术还没学到家。\n");
                if (jingli<50)
                        return notify_fail("你的精力不足。\n");
                //if (wizardp(who) && !wizardp(me))
                if (wizardp(who))
                        return notify_fail("你无法易容成巫师。\n");
        
                djingli=15+400/(jingli-20); 
        
                message_vision(HIY "$N从身上找出一些神秘的药物，在手里揉了揉，往脸上一阵乱图，变得和$n一模一样,真是真假难分！\n" NOR,me,who);
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
                        message_vision(HIY"只见$N将脸上的药物除去，恢复了本来面貌。\n" NOR,me);
    }

    return 1;
}

int help(object me)
{
        write(@HELP

指令格式 ： yirong [<人物>|<NPC>|<me>]

易容术，这个指令让你易容成其他人物的模样。是否能易容，还要取决于
你的易容术修为和精力大小。

相关指令： shipo
HELP
        );
        return 1;
}




