//jing.c  「惊天动地」
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;

    if( !target ) target = offensive_target(me);

    if( !target || !target->is_character() || !me->is_fighting(target) )
   return notify_fail("「"+HIC"惊天动地"NOR+"」只能对战斗中的对手使用。\n");

    if( (int)me->query_skill("taixuan-gong", 1) < 200 )
   return notify_fail("你的太玄功火候不够，无法施展「"+HIC"惊天动地"NOR+"」。\n");

    if( (int)me->query("neili") < 1200 )
   return notify_fail("你的内力修为还不够高。\n");

    msg = HIB "$N默运太玄功，刹那间天昏地暗，四下里飞沙走石，\n"NOR;
    msg += HIB "$N已然施展出「"+HIC"惊天动地"NOR+HIB+"」，一阵狂风般击向$n。\n"NOR;  

    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2) { 
      me->start_busy(3);
   target->start_busy(random(3));

   damage = (int)me->query_skill("taixuan-gong", 1) * 5;

   damage = damage + random(damage);

   target->receive_damage("qi", damage);
   target->receive_wound("qi", damage/2);
   me->add("neili", -600);
   msg += HIR"
$n只觉狂风中一股大力涌来，躲无可躲，被重重击中，脏腑内若翻江倒海，口中鲜血已如鲸喷般射出！！\n"NOR;
    } else
    {
       me->start_busy(1);
       msg += HIG"可是$p看破了$P的攻势，极为迅捷地向后跃出，将这「"+HIC"惊天动地"NOR+HIG+"」躲了过去。\n"NOR;
    }
    message_vision(msg, me, target);

    if(!target->is_fighting(me)) target->fight_ob(me);
//    if(userp(target)) target->fight_ob(me);
//    else if( !target->is_killing(me) ) target->kill_ob(me);
    return 1;
}

