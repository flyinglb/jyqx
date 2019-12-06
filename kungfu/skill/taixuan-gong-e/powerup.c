// powerup.c ̫��������

#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if( target != me )
		return notify_fail("��ֻ�������Լ���ս������\n");
	if( (int)me->query("neili")<800)
		return notify_fail("�������������\n");
	if( (int)me->query_temp("powerup"))
		return notify_fail("���Ѿ����˹����ˡ�\n");

	skill = me->query_skill("taixuan-gong");

	message_vision(
	HBWHT+HIB "$NǱ��̫������ȴ��ƽ�������һ�����磬$N�ѱ���������Ŀ���С�\n" NOR, me);

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
	message_vision(HBBLU+HIW "$N��̫����������ϣ���Ұ��绯�����̶�ȥ��\n" NOR, me);
}
