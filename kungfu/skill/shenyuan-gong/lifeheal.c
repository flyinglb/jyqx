// lifeheal.c ��Ԫ��

#include <ansi.h>

int exert(object me, object target)
{
    if( !objectp(target) )
		return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�\n");

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("���������Ϊ������\n");

//        if( (int)me->query_skill("medicine", 1) < 120 )
//                return notify_fail("�㱾������ĵȼ��������޷�Ϊ�������ˡ�\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("�������������\n");

	if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
		return notify_fail( target->name() +
			"�Ѿ����˹��أ����ܲ�����������𵴣�\n");
    if (target->query("eff_qi") >= target->query("max_qi"))
        return notify_fail(target->name() + "��û�����ˡ�\n");

	message_vision(
          HIY "$N��������������Ԫ��������������$n���ģ������ؽ���������$n����......\n\n"
		"$nֻ��һ������ԴԴ�������������ڣ�˲������ȫ�����Ѩλ��$n�³�һ\n\n"
		"����Ѫ����ɫ������������ˣ�����ȫ�������ޱȳ��棡����\n" NOR,
		me, target );

	target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
	target->add("qi", 10 + (int)me->query_skill("force")/3 );
	if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));

	me->add("neili", -100);
	me->set("jiali", 0);

	return 1;
}

