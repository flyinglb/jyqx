//leiting.c  「雷霆一击」
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;

    if( !target ) target = offensive_target(me);

    if( !target || !target->is_character() || !me->is_fighting(target) )
   return notify_fail("「"+HIY"雷"NOR+HIC"霆"NOR+HIG"一"NOR+HIR"击"NOR+"」只能对战斗中的对手使用。\n");

    if( (int)me->query_skill("huntian-qigong", 1) < 100 )
   return notify_fail("你的混天气功火候不够，使不出「"+HIY"雷"NOR+HIC"霆"NOR+HIG"一"NOR+HIR"击"NOR+"」。\n");

    if( (int)me->query_skill("xianglong-zhang", 1) < 100 )
   return notify_fail("你的降龙十八掌不够熟练，不会使用「"+HIY"雷"NOR+HIC"霆"NOR+HIG"一"NOR+HIR"击"NOR+"」。\n");

    if( (int)me->query("neili") < 500 )
   return notify_fail("你的内力修为还不够高。\n");

    msg = HIC "
$N默运混天气功，施展出「"+HIY"雷"NOR+HIC"霆"NOR+HIG"一"NOR+HIR"击"NOR+HIC+"」，全身急速转动起来，越来越快，就犹如一股旋风，骤然间，$N已卷向正看得发呆的$n。\n"NOR;  

    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3) { 
      me->start_busy(3);
   target->start_busy(random(3));

   damage = (int)me->query_skill("xianglong-zhang", 1)*4+(int)me->query_skill("huntian-qigong",1);

   damage = damage + random(damage);

   target->receive_damage("qi", damage);
   target->receive_wound("qi", damage/2);
   me->add("neili", -500);
   msg += HIR"
$n只见一阵旋风影中陡然现出$N的双拳，根本来不及躲避，被重重击中，五脏六腑翻腾不休，口中鲜血如箭般喷出！！！\n"NOR;
    } else
    {
       me->start_busy(1);
       msg += HIG"可是$p看破了$P的企图，闪在了一边。\n"NOR;
    }
    message_vision(msg, me, target);

    if(!target->is_fighting(me)) target->fight_ob(me);
//    if(userp(target)) target->fight_ob(me);
//    else if( !target->is_killing(me) ) target->kill_ob(me);
    return 1;
}

