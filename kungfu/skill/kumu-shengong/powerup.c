// powerup.c 枯木神功加力
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
    int skill;
    if( target != me ) 
        return notify_fail("你只能用枯木神功来提升自己的战斗力。\n");
    if( (int)me->query("neili") < 100  ) 
        return notify_fail("你的内力不够。\n");
    if( (int)me->query_temp("powerup") ) 
        return notify_fail("你已经在运功中了。\n");
    skill = me->query_skill("kumu-shengong",1);
    if (skill<60) return notify_fail("你的枯木神功还不够娴熟。\n");
    me->add("neili", -100);
    me->receive_damage("qi", 0);
    message_vision( BOLD "$N微一凝神，运起枯木神功，脸色忽然青黄变幻不定。\n" NOR, me);
    me->add_temp("apply/attack", skill/3);
    me->add_temp("apply/dodge", skill);
    me->set_temp("powerup", 1);
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill/2);
    if( me->is_fighting() ) me->start_busy(3);
    return 1;
}
void remove_effect(object me, int amount)
{
    if (!me)    return;
   if ( (int)me->query_temp("powerup") ) {
    me->add_temp("apply/attack", - amount);
    me->add_temp("apply/dodge", - amount);
    me->delete_temp("powerup");
    tell_object(me, BOLD"你的枯木神功运行完毕，将内力收回丹田。\n"NOR);
    }
}
