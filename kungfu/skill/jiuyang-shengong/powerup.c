// powerup.c 九阳神功加力
#include <ansi.h>
void remove_effect(object me, int amount);
int exert(object me, object target)
{
    int skill;
    if( target != me ) 
        return notify_fail("你只能用九阳神功来提升自己的战斗力。\n");
    if( (int)me->query("neili") < 100  ) 
        return notify_fail("你的内力不够。\n");
    if( (int)me->query_temp("powerup")>1 ) 
        return notify_fail("你已经在运功中了。\n");
    skill = me->query_skill("jiuyang-shengong",1);
	if (skill<60) return notify_fail("你的九阳神功还不够娴熟。\n");
    me->add("neili", -100);
    me->receive_damage("qi", 0);
    message_vision( MAG "$N微一凝神，运起九阳神功，全身骨节发出一阵爆豆般的声响。\n" NOR, me);
    me->add_temp("apply/attack", skill/3);
    me->add_temp("apply/dodge", skill/3);
    me->add_temp("powerup", 1);
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill/3);
    if( me->is_fighting() ) me->start_busy(3);
    return 1;
}
void remove_effect(object me, int amount)
{
    if (!me)    return;
   if ( (int)me->query_temp("powerup") ) {
    me->add_temp("apply/attack", - amount);
    me->add_temp("apply/dodge", - amount);
    me->add_temp("powerup",-1);
    if ( !(int)me->query_temp("powerup") )
    tell_object(me, BOLD"你的九阳神功运行完毕，将内力收回丹田。\n"NOR);}
}
int clean_up()
{
    return 1;
}
void reset()
{
}

