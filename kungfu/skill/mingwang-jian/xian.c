// xian.c  明王现体
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    object weapon;
    int damage;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("明王现体只能对战斗中的对手使用。\n");
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");
        
    if( (int)me->query_skill("mingwang-jian", 1) < 50 )
        return notify_fail("你的不动明王剑不够娴熟，不会使用「明王现体」。\n");
                            
    if( (int)me->query_skill("xiaowuxiang", 1) < 50 )
        return notify_fail("你的小无相功不够高，不能用来反震伤敌。\n");
            
    if( (int)me->query("neili", 1) < 300 )
        return notify_fail("你现在内力太弱，不能使用「明王现体」。\n");
            
    msg = HIR "$N微微一笑，猛吸一口气,欲使出以气驭剑绝技攻击$n。\n"NOR;
    if( !target->is_killing(me) ) target->kill_ob(me);
    if (random(me->query_skill("force")) > target->query_skill("force")/5 )
    {
        target->start_busy( (int)me->query_skill("mingwang-jian") / 30 + 1);
        
        damage = (int)me->query_skill("lamaism", 1);
        damage = damage +  (int)me->query_skill("xiaowuxiang", 1);
        damage = damage +  (int)me->query_skill("mingwang-jian", 1);
        
        target->receive_damage("qi", damage,me);
        target->receive_wound("qi", damage/2,me);
        me->add("neili", -damage);
        msg += HIY"只见$N手中剑光幻作一条金龙,腾空而起,倏的罩向$n,\n$n只觉一股大力铺天盖地般压来,登时眼前一花，两耳轰鸣,哇的喷出一口鲜血！！\n\n"NOR;
        me->start_busy(2);
    } else 
    {
        msg += YEL"可是$p猛地向前一跃,跳出了$P的攻击范围。\n"NOR;
        me->add("neili", -100);
        me->start_busy(4);
    }
    message_vision(msg, me, target);
    return 1;
}
