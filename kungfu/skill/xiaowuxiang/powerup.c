#include <ansi.h>
void remove_effect(object me, int amount);
int exert(object me, object target)
{
    int skill;
    if( target != me )
        return notify_fail("你只能用小无相功来提升自己的战斗力。\n");
    if( (int)me->query("neili") < 100  )
        return notify_fail("你的内力不够。\n");
    if( (int)me->query_temp("powerup") )
        return notify_fail("你已经在运功中了。\n");
    skill = me->query_skill("xiaowuxiang",1);
    if (skill<50) return notify_fail("你的小无相功还不够娴熟。\n");
    me->add("neili", -50);
    me->receive_damage("qi", 0);
    message_vision(
    HIW "$N微一凝神，无声无息地运起小无相功，把全身潜能提至极限。\n" NOR, me);
    me->add_temp("apply/attack", skill/3);
    me->add_temp("apply/dodge", skill/3);
    me->set_temp("powerup", 1);
    me->add("bellicosity",skill);
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill/2);
    if( me->is_fighting() ) me->start_busy(3);
    return 1;
}
void remove_effect(object me, int amount)
{
   if ( (int)me->query_temp("powerup") ) {
    me->add_temp("apply/attack", - amount);
    me->add_temp("apply/dodge", - amount);
    me->delete_temp("powerup");
    tell_object(me, "你的小无相功运行完毕，将内力收回丹田。\n");}
}
int clean_up()
{
    return 1;
}
void reset()
{
}

