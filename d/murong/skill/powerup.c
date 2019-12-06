// powerup.c ��Ԫ��

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if( target != me ) 
		return notify_fail("��ֻ������Ԫ���������Լ���ս������\n");

	if( (int)me->query("neili") < 100  ) 
		return notify_fail("�������������\n");
	if( (int)me->query_temp("powerup") ) 
		return notify_fail("���Ѿ����˹����ˡ�\n");

	skill = me->query_skill("force");
	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_vision(
	HIR "$N������Ԫ������Ŀ����һ��ֻ��$N����ɫ��ú�����ˡ�\n" NOR, me);

	me->add_temp("apply/attack", skill/2);
	me->add_temp("apply/dodge", skill/2);
	me->set_temp("powerup", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);

	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	me->add_temp("apply/attack", - amount);
	me->add_temp("apply/dodge", - amount);
	me->delete_temp("powerup");
	tell_object(me, "��������Ԫ�����������ջص��\n");
}

