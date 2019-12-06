// liumai.c - 六脉归宗
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("六脉归宗只能对战斗中的对手使用。\n");
        if( me->query_skill("finger") < 150 )
                return notify_fail("你在指法上的造诣不够，无法使用六脉归宗。\n");
        if( me->query_skill("dodge") < 150 )
                return notify_fail("你在轻功上的造诣不够，无法使用六脉归宗。\n");
        if( me->query("max_neili") < 800 || me->query("neili") < 1500 )
                return notify_fail("你的内力不够，无法施展六脉归宗！\n");
        message_vision(HIW"$N凌空跃起,使出了六脉神剑的最高绝技六脉归宗。\n" + HIC"六道金光疾射而出，射向$n！！！\n"NOR, me, target);
        me->add("neili", -500);
//        me->add("max_neili", -1);
        me->add_temp("apply/strength", 12*(int)me->query("str") );
        me->add_temp("apply/dexerity", 12*(int)me->query("dex") );
        COMBAT_D->do_attack(me, target);
        COMBAT_D->do_attack(me, target);
        COMBAT_D->do_attack(me, target);
        COMBAT_D->do_attack(me, target);
        COMBAT_D->do_attack(me, target);
        COMBAT_D->do_attack(me, target);
        COMBAT_D->do_attack(me, target);
        me->add_temp("apply/strength", -12*(int)me->query("str") );
        me->add_temp("apply/dexerity", -12*(int)me->query("dex") );
        me->start_busy(3);
        return 1;
}
