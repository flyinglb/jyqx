// cuo.c

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg;
 
        if( !me->is_fighting() )
                return notify_fail("「挫字决」只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");

        if( (int)me->query("neili") < 100 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("blade") < 50 ||
            me->query_skill_mapped("blade") != "taiji-dao")
                return notify_fail("你的「太极刀法」还不到家，无法使用「挫字决」！\n");

        msg = BBLU "$N使出太极刀绝技「挫字决」，身法突地变得异常灵动飘忽！\n" NOR;
        message_vision(msg, me);

        me->clean_up_enemy();
        ob = me->select_opponent();

        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));

        me->add("neili", -100);
        me->start_busy(random(3));

        return 1;
}

