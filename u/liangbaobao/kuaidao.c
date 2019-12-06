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
        extra = me->query_skill("murong-daofa",1);
        if ( extra < 200) return notify_fail("你的慕容刀法还不够纯熟！\n");
        if((int)me->query_skill("blade", 1) < 100 )
                return notify_fail("你的基本刀法不够娴熟，不能在刀招中夹杂使用快刀。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你手里没有刀，无法使用快刀！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("快刀只能对战斗中的对手使用。\n");
        if ((int)me->query("neili")<150)
                return notify_fail("你的内力不够。\n"); 
        me->add("neili",-150);
        weapon = me->query_temp("weapon");
        message_vision(HIY"$N使出慕容剑法中的绝招快刀，手中的"+weapon->name()+"闪电般向$n攻出！\n\n" NOR,me,target);        
     if (random((int)me->query_skill("dodge", 1)/2)>random((int)target->query_skill("dodge")/5 ) )
        {
        COMBAT_D->do_attack(me,target, weapon); 
        message_vision(HIR"上一刀！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIR"下一刀！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIR"左一刀！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIR"右一刀！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIR"最后一刀！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        
        
        message_vision(HIY"结果$n被攻了个措手不及！\n" NOR,me,target);
        me->start_busy(5);
        } else { 
                message_vision(HIY"可是$n看破了$N的招式,趁机发动进攻！\n" NOR,me,target);
                me->start_busy(2);
        }        
        return 1;
}

