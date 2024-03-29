// fugu.c 金蛇游身掌-附骨缠身

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
//        object weapon;
//        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("附骨缠身只能对战斗中的对手使用。\n");

        if( me->query_temp("weapon"))
                return notify_fail("你不是空手，不能使用附骨缠身。\n");

        if( (int)me->query_skill("jinshe-zhang", 1) < 100 )
                return notify_fail("你的金蛇掌不够娴熟，不会使用附骨缠身。\n");

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("你现在内力太弱，不能使用附骨缠身。\n");

        msg = HIC "$N大喝一声，缠身而上左手一探刁住$n手腕，右掌猛下杀手！\n"NOR;
        message_vision(msg, me, target);

        if( !target->is_fighting(me) ) target->fight_ob(me);

        if (random(me->query_skill("strike")) > target->query_skill("dodge")/2 )
        {
                me->clean_up_enemy();
                target = me->select_opponent();

                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);

                me->add("neili", -50);
                me->start_busy(random(2));
                msg = HIR"结果$n被$N的左手所制，在「附骨缠身」下，竟然无法还手！\n"NOR;
        }
        else
        {
                me->start_busy(3);
                msg = CYN"可是$p识破了$P这一招，手肘一送，摆脱了对方控制。\n"NOR;
        }
        message_vision(msg, me, target);

        return 1;
}
