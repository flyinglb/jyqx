// heal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������\n");

	if( (int)me->query("force") - (int)me->query("max_force") < 50 )
		return notify_fail("�������������\n");

	if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 3 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

	write( HIW "��ȫ����ɣ���������ʼ�˹����ˡ�\n" NOR);
	message("vision",
		HIW + me->name() + "�������˹����ˣ�����һ���һ��ף����ã��³�һ����Ѫ����ɫ�������ö��ˡ�\n" NOR,
		environment(me), me);

	me->receive_curing("kee", 15 + (int)me->query_skill("force")/5 );
	me->add("force", -50);
	me->set("force_factor", 0);

	return 1;
}
