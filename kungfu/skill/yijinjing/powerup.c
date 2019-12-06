// powerup.c �׽����

#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if( target != me )
		return notify_fail("��ֻ�������Լ���ս������\n");
	if( (int)me->query("neili")<200)
		return notify_fail("�������������\n");
	if( (int)me->query_temp("powerup"))
		return notify_fail("���Ѿ����˹����ˡ�\n");
	if( (int)me->query_temp("jingang") ) 
		return notify_fail(HIG"���ȫ�����������ڴ���ȭ���ˡ�\n"NOR);
	if( (int)me->query_temp("zuida") ) 
		return notify_fail(HIG"����Ϣ�����ڰ�������У�һʱ�᲻���׽�񹦡�\n"NOR);

	skill = me->query_skill("force");

	message_vision(
	HIR "$N���һҧ�����һ����Ѫ�������׽���ѽ�ȫ��Ǳ����������\n" NOR, me);

	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("powerup", 1);
	me->add("neili", -100);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);

	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	me->add_temp("apply/attack", - amount);
	me->add_temp("apply/dodge", - amount);
	me->delete_temp("powerup");
	tell_object(me, "����׽��������ϣ��������ջص��\n");
}
