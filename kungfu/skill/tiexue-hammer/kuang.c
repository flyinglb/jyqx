//kuang.c 
// Modified by Venus Oct.1997
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int extra;
        object weapon;
    string msg;
        extra=me->query_skill("tiexue-hammer",1);
    if( !target ) target = offensive_target(me);
    if( !target||!target->is_character()||!me->is_fighting(target) )
    return notify_fail("你只能对战斗中的对手使用「狂锤」。\n");
    if( (int)me->query_skill("tiexue-hammer",1) < 70)
    return notify_fail("你目前功力还使不出「狂锤」。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "hammer")
                        return notify_fail("你使用的武器不对。\n");
        if( (int)me->query("neili") < 100 )
    return notify_fail("你的内力不够。\n");
    me->add("neili", -60);
    msg = HIR"$N大叫一声，看锤！就在这一瞬之间，"+
    "$N已砸出三锤！锤夹杂着风，含着风影！$n只觉得全身气血倒流！"NOR;
        message_vision(msg, me, target);                
        msg = HIY  "---第一锤！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "-----第二锤！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "-------最后一锤！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->start_busy(2);


    return 1;
}


