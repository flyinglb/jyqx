// tuwu.c

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int skill;
//        string msg;
	object weapon;

	if( !target ) target = offensive_target(me);
	if (me->query_temp("jinshe/tuwu"))
		return notify_fail("����õĽ�������û�����žͳ��С�\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��������ֻ����ս����ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
            || (string)weapon->query("id") != "jinshe zhui")
           return notify_fail("��û�ý���׶������ʹ�þ��У�\n");

	if( (int)me->query_skill("jinshe-zhui", 1) < 100 )
		return notify_fail("��Ľ���׶��������죬����ʹ�ý�������\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("�����������ˡ�\n");

	skill = me->query_skill("jinshe-zhui", 1);

	me->add("neili", -200);
	target->receive_damage("qi", (int)skill/ 3);

	message_vision(
        HIY "ֻ��һ����ɨҶ��������У�$N���е�"YEL"����׶"HIY"������Ŀ�Ĺ�â����ҫ��
$n��ð�𻨣�������������������ǰһ���ص������⣬$nɶҲ�������ˣ�\n" NOR, me, target);
	me->set_temp("jinshe/tuwu", 1);
	target->set_temp("block_msg/all",1);
	call_out("tuwu_end", (int) skill/30, me, target);

	return 1;
}
void tuwu_end(object me, object target)
{
	target->enable_player();
	message_vision("$NĨ��Ĩ������"HIR"��Ѫ"NOR"�������������ۡ�\n", target);
	target->set_temp("block_msg/all", 0);
	write(HIR"������Ĩ������������Ѫ����������Χ���龰��\n"NOR);
	me->delete_temp("jinshe/tuwu");

	return;
}
