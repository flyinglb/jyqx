// ren.c  两仪剑法「天地同仁」

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    object weapon;

    if (!target ) target = offensive_target(me);
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"开什么玩笑，没装备剑就想使「天地同仁」？\n"NOR);
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「天地同仁」只能对战斗中的对手使用。\n");
    if ((int)me->query_skill("liangyi-jian", 1) < 60 )
        return notify_fail(WHT"你两仪剑法不够娴熟，使不出「天地同仁」。\n"NOR);
    if ((int)me->query_skill("taiji-shengong", 1) < 90 )
        return notify_fail(RED"你太极神功火候不够，使不出「天地同仁」。\n"NOR);
    if ((int)me->query("max_neili")<400)
        return notify_fail(RED"你内力修为不足，无法运足内力。\n"NOR);
    if ((int)me->query("neili")<200)
    {
        return notify_fail(HIC"你现在内力不够，没能将「天地同仁」使完！\n"NOR);
    }
    msg = HIC "$N手中长剑剑芒跃动，剑光暴长，剑尖颤动似乎分左右刺向$n，\n"NOR;
    msg += HIC"$n看到剑光偏左，疾侧身右转，但只这一刹，剑光刹时袭向右首！\n"NOR;
    if (random(me->query_skill("force")) > target->query_skill("force")/2|| 
       random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
    {
        me->start_busy(2);
        target->start_busy(random(3));
        damage = (int)me->query_skill("liangyi-jian", 1) + (int)me->query_skill("sword", 1)/2;
        damage = damage/2 + random(damage);
        target->receive_damage("qi", damage/2);
        target->receive_wound("qi", damage/3);
    msg += HIC"$n疾忙左转，却发现$N的剑根本没有右偏，一式「天地同仁」在\n"NOR;
    msg += HIC"$n左胸留下一个血洞！$n一低头，看到胸口鲜血涌泉喷出！\n"NOR;
        me->add("neili", -damage/5);
    } else
    {
        me->start_busy(2);
    msg += HIY"可是$p轻轻一笑，侧身右转，果然$P的剑式突然左展，在$p身前\n"NOR;
    msg += HIY"划过，仅差半寸。一根毫毛都没伤到。\n"NOR;
    }
    message_vision(msg, me, target);
    if(!target->is_fighting(me)) target->fight_ob(me);
//    if(userp(target)) target->fight_ob(me);
//    else if( !target->is_killing(me) ) target->kill_ob(me);
    return 1;
}
