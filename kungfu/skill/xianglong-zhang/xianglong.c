// xianglong ������
// by king 97.05

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me);

int perform(object me)
{
	int skill, count;

	if( (int)me->query_temp("xianglong") ) 
		return notify_fail("���Ѿ����˹����ˡ�\n");
	if( !me->is_fighting() )
		return notify_fail("������ֻ����ս����ʹ�á�\n");
	if( (int)me->query("neili") < 300  ) 
		return notify_fail("�������������\n");

	count = me->query_str();
	skill = me->query_skill("xianglong-zhang",1);
	if( skill < 80  ) 
		return notify_fail("��Ľ���ʮ������Ϊ��������\n");

	me->add("neili", -100);

	message_vision( HIR "$N����һ�������������󷨣����ԽսԽ�£�\n" NOR, me);

	me->set_temp("xianglong", 1);
	me->set_temp("str_count", (int)count/5);
	me->set_temp("str_no", 0);
	me->set_temp("display_no", 0);
	me->start_call_out( (: call_other,  __FILE__, "remove_effect", me :), skill/2 );

	return 1;
}

void remove_effect(object me)
{
	int dmount;
	if ( (int)me->query_temp("xianglong") ) {
	dmount = (int)me->query_temp("str_no")*(int)me->query_temp("str_count");
	me->add_temp("str", - dmount );
	me->delete_temp("xianglong");
	me->delete_temp("str_count");
	me->delete_temp("str_no");
	me->delete_temp("display_no");
	tell_object(me, CYN"��Ľ�����������ϣ��������ջص��\n"NOR);}
}
