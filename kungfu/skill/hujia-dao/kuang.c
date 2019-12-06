#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    object weapon;
    int damage;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target||!target->is_character()||!me->is_fighting(target) )
    return notify_fail("你只能对战斗中的对手使用「狂风式」。\n");
    if( (int)me->query_skill("hujia-dao",1) < 100)
    return notify_fail("你目前功力还使不出「狂风式」。\n");
    if( (int)me->query("neili") < 400 )
    return notify_fail("你的内力不够使出「狂风式」。\n");
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
    return notify_fail("「狂风式」必须拿着刀才能使出！\n");
    me->add("neili", -60);
    msg = HIC"$N淡然一笑，本就快捷绝伦的刀法骤然变得更加凌厉！就在这一瞬之间，\n\n"+
    "$N已劈出十三刀！！\n\n"+
    "刀夹杂着风，风里含着刀影！$n只觉得心跳都停止了！\n\n"NOR;
    me->start_busy(2);

    if( random(me->query("combat_exp")) >
      (int)target->query("combat_exp")/3 ) {
    target->start_busy( (int)me->query_skill("hujia-dao") / 20 );
    damage = (int)me->query_skill("hujia-dao", 1)+(int)me->query_skill("blade", 1)/2;
    damage = damage + random(damage);

    target->receive_damage("qi", damage);
    target->receive_wound("qi", damage/2);
    target->receive_damage("jing", damage/2);
    target->receive_wound("jing", damage/3);
   msg += HIR
"只见$n已被$N切得体无完肤，血如箭般由全身喷射而出！\n"NOR;
    } else {
    msg += HIC "可是$p急忙抽身躲开，$P这招没有得逞。\n" NOR;
    }
    message_vision(msg, me, target);
    if(userp(target)) target->fight_ob(me);
    else if( !target->is_killing(me) ) target->kill_ob(me);

    return 1;
}

