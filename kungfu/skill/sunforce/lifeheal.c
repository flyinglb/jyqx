// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( !target )
		return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�\n");

	if( (int)me->query("force") - (int)me->query("max_force") < 150 )
		return notify_fail("�������������\n");

	if( (int)target->query("eff_kee") < (int)target->query("max_kee") / 5 )
		return notify_fail( target->name() + "�Ѿ����˹��أ����ܲ���������������\n");

	message_vision(
		HIY "$N�������������ڹ�������������$n���ģ������ؽ���������$n����....\n\n"
		"���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n" NOR,
		me, target );

	target->receive_curing("kee", 15 + (int)me->query_skill("force")/3 );
	me->add("force", -150);
	me->set("force_factor", 0);

	return 1;
}
