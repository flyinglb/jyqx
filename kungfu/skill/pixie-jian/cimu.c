// cimu.c 刺目

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[刺目]只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
                
        if( (int)me->query_skill("pixie-jian", 1) < 90 )
                return notify_fail("你的辟邪剑法不够娴熟，不会使用「刺目」。\n");
                                
        if( (int)me->query_skill("kuihua-xinfa", 1) < 50 )
                return notify_fail("你的葵花心法不够高，不能用来[刺目]。\n");
                        
        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("你现在内力太弱，不能使用「刺目」。\n");
                        
        msg = HIC "$N露出鬼魅的笑容，身形飘忽,左幻右闪,忽略忽伸地向$n的眼睛刺去。\n"NOR;

        if( !target->is_killing(me) ) target->kill_ob(me);

        if (random(me->query_skill("force")) > target->query_skill("force")/6 )
        {
                target->start_busy( (int)me->query_skill("pixie-jian") / 80 + 1);
                
                damage = (int)me->query_skill("kuihua-xinfa", 1);
                damage = damage +  (int)me->query_skill("kuihua-xinfa", 1);
                damage = damage +  (int)me->query_skill("pixie-jian", 1);
                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                me->add("neili", -damage/2);
                msg += HIC"只见$N手中剑光幻出七八个$N,腾空而起,倏的刺向$n的眼睛,\n$n方寸大乱，只觉眼睛一阵刺痛，鲜血从眼睛顺着脸颊流了下来！\n"NOR;
                me->start_busy(2);
        } else 
        {
                msg += HIY"$n情急智生，抬手也向$P击去，迫得$P回剑跃开收回这招【刺目】。\n"NOR;
                me->add("neili", -100);
                me->start_busy(2);
        }
        message_vision(msg, me, target);

        return 1;
}

