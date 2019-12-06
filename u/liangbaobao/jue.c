// jue.c 绝剑

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[绝剑]只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
                
        if( (int)me->query_skill("huifeng-jian", 1) < 90 )
                return notify_fail(WHT"你的回风拂柳剑法不够娴熟，不会使用「绝剑」。\n");
                                
        if( (int)me->query_skill("linji-zhuang", 1) < 90 )
                return notify_fail(RED"你的临济十二庄不够高，不能用来[绝剑]。\n");
                        
        if( (int)me->query("neili", 1) < 500 )
                return notify_fail(YEL"你现在内力太弱，不能使用「绝剑」。\n");
                        
        msg = HIG "$N手中剑光顿然消失在空中，但仅仅呆了一瞬间，消失的剑光却\n"NOR;
        msg += HIG "已化做无数剑影欺到了$n面前，却又在突然之间转向$n\n"NOR;
        msg += HIG "的面门、咽喉、檀中、丹田、会阴等无数要害。这一剑足以叫人\n"NOR;
        msg += HIG "死无完尸。\n\n"NOR;

        if( !target->is_killing(me) ) target->kill_ob(me);

        if (random(me->query_skill("sword")) > target->query_skill("dodge")/6 )
        {
                target->start_busy( (int)me->query_skill("huifeng-jian") / 70 + 1);
                
                damage = (int)me->query_skill("huifeng-jian", 1);
                damage = damage +  (int)me->query_skill("huifeng-jian", 1);
                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                target->receive_damage("jing", damage/2);
                target->receive_wound("jing", damage/3);
                me->add("neili", -damage);
                msg += HIR"只见$N手中剑光在$n身上幻化出无数血箭，\n$n只觉身体每一部分都要离自己而去！\n"NOR;
                me->start_busy(3);
        } else 
        {
                msg += HIG"$n情急智生，抬手也向$P击去，迫得$P回剑跃开收回这招绝剑。\n"NOR;
                me->add("neili", -100);
                me->start_busy(3);
        }
        message_vision(msg, me, target);

        return 1;
}

