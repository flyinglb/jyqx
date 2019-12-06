// duo.c 空手入白刃
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
    string msg;
    object weapon, weapon2, target;
    int skill, dp;
    me->clean_up_enemy();
    target = me->select_opponent();
     skill = me->query_skill("shexing-diaoshou",1);
    if( !(me->is_fighting() ))
        return notify_fail("万蛇缠身只能对战斗中的对手使用。\n");
 
    if (objectp(weapon = me->query_temp("weapon")) && objectp(weapon = me->query_temp("weapon")))
        return notify_fail("你必须空手。\n");
    if (!objectp(weapon2 = target->query_temp("weapon")))
        return notify_fail("对方没有兵刃，你的万蛇缠身不会有任何作用.\n");
    if( skill < 50)
       return notify_fail("你的蛇形刁手等级不够, 不能万蛇缠身！\n");
    if( me->query("neili") < 50 )
       return notify_fail("你的内力不够，无法使出万蛇缠身！\n");
 
     msg = CYN "$N屏息凝神，身发迅速加快，使出了蛇形刁手的绝技--万蛇缠身！ \n";
    message_vision(msg, me);
 
     dp = target->query("combat_exp") / 5000;
    if( dp < 1 )
        dp = 1;
    if( random(skill) > dp )
    {
        if(userp(me))
            me->add("neili",-50);
msg = CYN "$n面对重重身影不知所措，手腕一麻，手中兵刃脱手而出！\n" NOR;
        target->start_busy(2);
        weapon2->move(me);
        me->start_busy(2);
    }
    else
    {
        msg = "可是$n沉着应战，$N的万蛇缠身没有起到任何作用。\n"NOR;
        me->start_busy(4);
    }
    message_vision(msg, me, target);
    return 1;
}
