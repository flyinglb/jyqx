// powerup.c 五毒神功加力
#include <ansi.h>
void remove_effect(object me, int amount);
int exert(object me, object target)
{
    int skill;
    if( target != me )
        return notify_fail("你只能用五毒神功提升自己的战斗力。\n");
    if( (int)me->query("neili") < 100  )
        return notify_fail("你的内力不够。\n");
    if( (int)me->query_temp("powerup") )
        return notify_fail("你已经在运功中了。\n");
    skill = me->query_skill("wudu-shengong",1);
    if (skill<50) return notify_fail("你的五毒神功还不够娴熟。\n");
    me->add("neili", -70);
    me->receive_damage("qi", 0);
    message_vision(
    HIR "$N微一凝神，将毒性和内力融合为一并发了出来。\n" NOR, me);
    me->add_temp("apply/attack", skill/4);
    me->add_temp("apply/dodge", skill/4);
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
    tell_object(me, "你的五毒神功运行完毕，将内力收回丹田。\n");}
}
int clean_up()
{
    return 1;
}
void reset()
{
}

