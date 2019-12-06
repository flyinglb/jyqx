//Edit by cloth 2000-09-19
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        int extra;
        object weapon;
        extra = me->query_skill("shenyuan-gong",1);
        if ( extra < 100) return notify_fail("你的神元功还不够纯熟！\n");
        extra = me->query_skill("murong-jianfa",1);
        if ( extra < 100) return notify_fail("你的慕容剑法还不够纯熟！\n");
        if((int)me->query_skill("sword", 1) < 100 )
        return notify_fail(RED"你基本刀法不够，「快剑」不成招式。\n"NOR);
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［快剑］只能对战斗中的对手使用。\n");
        if ((int)me->query("neili")<250)
                return notify_fail("你的内力不够。\n"); 
        me->add("neili",-250);
        weapon = me->query_temp("weapon");
        message_vision(HIM"$N使出慕容剑法中的绝招［快剑］，一招连环六剑，手中的"+weapon->name()+"
闪电般向$n攻出六剑！\n\n" NOR,me,target);   
     if (random((int)me->query_skill("dodge", 1)/2)>random((int)target->query_skill("dodge")/5 ) 
)
        {
        COMBAT_D->do_attack(me,target, weapon); 
        message_vision(HIW"第一剑！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIC"第二剑！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIR"第三剑！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIY"第四剑！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIB"第五剑！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);


        message_vision(WHT"$N连出六剑，结果$n被攻了个手忙脚乱！\n" NOR,me,target);
        me->start_busy(2);
        } else { 
                message_vision(HIC"可是$n看破了$N的招式,趁机发动进攻！\n" NOR,me,target);
                me->start_busy(1);
        }        
        return 1;
}
