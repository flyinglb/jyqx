// hubo.c
// modified by risc  in 1/1/2001
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me)
{
	string msg;
	int count;

    if( me->is_busy() )
	return notify_fail("你的动作还没有完成，不能使用「双手互博之术」。\n");
    if (!me->query_skill("hubo",1))
       return notify_fail("你不会「双手互博之术」。\n");
    if( me->query_skill("hubo",1) < 100 
    && (me->query_temp("weapon") || me->query_temp("secondary_weapon")) )
       return notify_fail("你只有空手才能用「双手互博之术」。\n");
//    if (me->query("gender")!="男性")
//       return notify_fail("你不能使用「双手互博之术」。\n");
      if (me->query("int")> 25)
         return notify_fail("你不能使用「双手互博之术」。\n");
    if( !me->is_fighting() )
        return notify_fail("「双手互博之术」只能在战斗中使用。\n");

    if( (int)me->query("jing") < 70 ) return notify_fail("你的精不够！\n");
    if( (int)me->query("neili") < 150 )
        return notify_fail("你的内力不够！\n");

/*
    if (me->query("hubo_busy_tag"))
        return notify_fail("你的心神还不能集中！\n");
*/
    if((time() - (int)me->query_temp("last_hubo_time") < 3)){
        write("你的心神还不能集中，无法使用左右互搏！\n");
	return 1;
    }

    msg = HIY "$N平心静气，灵台空明，使出「双手互博之术」，双手同时出招！\n" NOR;

    message_vision(msg, me);
    count = (40 - (int)me->query("int")) / 5 + (int)me->query_skill("hubo") / 30 ;
    if( count < 1 ) count = 1 ;
    if ( count > 6 ) count = 6 ;
    while( count-- )
    {
		object ob;

	me->clean_up_enemy();
	ob = me->select_opponent();
        if(!ob || (environment(ob) != environment(me))) 
        {
            message_vision(CYN "$N突然心中一乱，已不能继续双手互博！\n" NOR, me);
			break;
        }
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        me->set_temp("last_hubo_time",time()); //by robin

//      if (!me->query("hubo_busy_tag")) me->set_temp("hubo_busy_tag",1);// by cmd
//      COMBAT_D->fight(me, ob) ;
    }
//   remove_call_out("clean_hubo_tag");
//   call_out("clean_hubo_tag",3,me);
//by robin
// me->start_busy(1) by cmd
    me->receive_damage("jing", 50);
    me->add("neili", -100);
    return 1;
}

void clean_hubo_tag(object me)
{
    me->delete("hubo_busy_tag");
}
int help(object me)
{
        write(@HELP
指令格式 : hubo
 
这个指令可以让你在对敌时使用双手互博之术,快速出招。
 
HELP
    );
    return 1;
}
