// san.c  天女散花
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    object weapon;
    int damage;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「天女散花」只能对战斗中的对手使用。\n");
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");
        
    if( (int)me->query_skill("tianyu-qijian", 1) < 80 )
        return notify_fail("你的天羽奇剑不够娴熟，不会使用。\n");
    if (!me->visible(target))    return notify_fail("你看不到"+target->name()+"。\n");
                            
  if( (string)me->query_skill_mapped("force")!="bahuang-gong" || (int)me->query_skill("bahuang-gong", 1) < 50 )
        return notify_fail("你的八荒六合唯我独尊功没有准备或功力不够高。\n");
    if( (int)me->query("neili", 1) < 300 )
        return notify_fail("你现在内力太弱，不能使用「天女散花」。\n");
            
    msg = HIM "$N凝神息气，手腕疾抖，使出天羽奇剑中的绝招--“天女散花”。只见千万个剑花铺天盖地飞向$n。\n\n"NOR;
  if( !target->is_killing(me) ) target->kill_ob(me);
    if (random(me->query_skill("force")) > target->query_skill("force")/3 )
    {
        target->start_busy( (int)me->query_skill("tianyu-qijian") / 20 + 2);
        
        damage = (int)me->query_skill("tianyu-qijian", 1);
        damage = damage +  (int)me->query_skill("bahuang-gong", 1)* 0.5;
        damage = damage +  (int)me->query_skill("sword", 1)* 0.75;
        
        target->receive_damage("qi", damage,me);
        target->receive_wound("qi", damage/2,me);
        me->add("neili", -damage/2);
        msg += HIR"$n只觉一股热流穿心而过，喉头一甜，鲜血狂喷而出！\n"NOR;
        me->start_busy(6);
    } else 
    {
        msg += YEL"可是$p猛地向后一跃,跳出了$P的攻击范围。\n"NOR;
        me->add("neili", -100);
        me->start_busy(3);
    }
    message_vision(msg, me, target);
    return 1;
}

