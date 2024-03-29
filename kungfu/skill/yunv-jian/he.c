// he.c 玉女剑-双剑合璧

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("双剑合璧只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if( (int)me->query_skill("yunv-xinfa", 1) < 80 )
                return notify_fail("你的玉女心法不够娴熟，不能使用双剑合璧。\n");

        if( (int)me->query_skill("yunv-jian", 1) < 80 )
                return notify_fail("你的玉女剑法不够娴熟，不能使用双剑合璧。\n");

        if( (int)me->query_skill("quanzhen-jian", 1) < 50 )
                return notify_fail("你的全真剑法不够娴熟，不能使用双剑合璧。\n");

        if( (int)me->query("neili", 1) < 400 )
                return notify_fail("你现在内力太弱，不能使用双剑合璧。\n");

        msg = YEL "$N左手以全真剑法剑意，右手化玉女剑法剑招，双剑合璧同时刺出。\n"NOR;

        if( !target->is_fighting(me) ) target->fight_ob(me);

        if (random(me->query_skill("force")) > target->query_skill("force")/2 )
        {
                me->start_busy(2);

                damage = (int)me->query_skill("yunv-jian", 1) + (int)me->query_skill("quanzhen-jian",1);
                damage = damage + (int)me->query_skill("force",1) ;
                //(玉女剑法+全真剑法级别+基本内功)

                damage = damage/2 + random(damage);

                target->receive_damage("qi", damage);
                target->start_busy(4);
                me->add("neili", -350);

                msg += HIR"$n看到$N双剑飞舞，招式中所有破绽都为另一剑补去，竟不知
如何是好！\n"NOR;
                msg += HIR"一呆之下，$N的剑招已经破式而入！\n"NOR;

        }
        else
        {
                me->start_busy(3);
                msg += CYN"可是$p看破了$P的企图，将自己的全身上下护得密不透风，
令$P无计可施。\n"NOR;
        }
        message_vision(msg, me, target);

        return 1;
}
