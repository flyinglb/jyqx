// xiaohun.c 黯然消魂
// By Kayin @ CuteRabbit Studio 99-4-16 19:18 new
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        string msg;
	int extra;
        object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("anranxiaohun-zhang",1);
        if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「黯然消魂」只能在战斗中使用。\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「黯然消魂」只能空手使用。\n");		
       
	 if( (int)me->query("neili") < 1000 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("anranxiaohun-zhang",1) < 120 )
                return notify_fail("你的黯然消魂掌火候不够，无法使用「黯然消魂」！\n");
        if( (int)me->query_skill("xuantie-sword",1) < 80 )
                return notify_fail("你的玄铁剑法火候不够，无法领悟「黯然消魂」！\n");
        if( (int)me->query_skill("force",1) < 150 )
                return notify_fail("你的内功修为不够，无法使用「黯然消魂」！\n");
//	me->add_temp("apply/attack",extra*2);
//	me->add_temp("apply/damage",extra*2);
	weapon = me->query_temp("weapon");

    if( !living(target) || random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
    {
        msg = HIM "$N心如止水，心中思念着$N的妻子，无意之中使出了"HIR"“黯然消魂”！\n" NOR;
        msg += HIM   "就似傍晚的遥烟，顿时天地间产生一丝苦涩！\n" NOR;
	         message_vision(msg, me, target);                
	 msg =  HIC  "\n   黯 \n" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "\n          然\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "\n                   消\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "\n                            魂\n" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "\n                                     掌\n" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
//      me->add_temp("apply/attack",-extra*2);
//	me->add_temp("apply/damage",-extra*2);
        me->add("neili", -500);
        me->start_busy(4);
        target->start_busy(4);
    }
    else
    {
       msg = HIY  "可是$p"+ HIY +"看破了$P的企图，并没有上当。\n" NOR;
         me->start_busy(1);
        target->start_busy(1);
    }
        return 1;

}


