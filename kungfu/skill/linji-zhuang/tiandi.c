// tiandi.c

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);

	if (me->query_condition("linji_tiandi"))
		return notify_fail("���Ѿ��������ׯ�ˣ�\n");

	if (me->query("gender") != "Ů��")
		return notify_fail("�㲻�Ǵ���֮�壬���������ׯ��\n");

	if( me->is_fighting() )
		return notify_fail("ս�����޷������ׯ��\n");

	if( (int)me->query("neili") < 100)
		return notify_fail("�������������\n");

	if( (int)me->query_skill("linji-zhuang",1) < 30)
		return notify_fail("����ټ�ׯ���𲻹���\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "�Ѿ����˹��أ��޷��˹���\n");

	message_vision(
HIM "$N���������������ׯ���������������ϣ������ؽ�����������������....\n"
"���˲��ã�$N������������Ө����ɫ����������������͸���ഺ����Ϣ��\n" NOR,
	me );
	me->apply_condition("linji_tiandi", (int)skill/20);
	me->add("neili", -100);
	me->add("jing", -20);
	me->add("eff_jing", -10);
	me->add("per", (int)skill/20);
	me->set("linji/per", (int)skill/20);
	return 1;
}

