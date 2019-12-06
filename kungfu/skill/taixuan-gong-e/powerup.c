// powerup.c 太玄功加力

#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if( target != me )
		return notify_fail("你只能提升自己的战斗力。\n");
	if( (int)me->query("neili")<800)
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_temp("powerup"))
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("taixuan-gong");

	message_vision(
	HBWHT+HIB "$N潜运太玄功，却在平地里刮起一阵旋风，$N已被裹绕在迷目风中。\n" NOR, me);

	me->add_temp("apply/attack", skill/2);
	me->add_temp("apply/dodge", skill/2);
	me->set_temp("powerup", 1);
	me->add("neili", -120);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/2 :), skill);

	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	me->add_temp("apply/attack", - amount);
	me->add_temp("apply/dodge", - amount);
	me->delete_temp("powerup");
	message_vision(HBBLU+HIW "$N的太玄功运行完毕，遍野狂风化做飞烟而去。\n" NOR, me);
}
