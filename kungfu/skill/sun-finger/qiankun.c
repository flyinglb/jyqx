// qiankun.c һ��ָ ��һָǬ����

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

        if( !me->is_fighting() )
           return notify_fail("��һָǬ����ֻ����ս����ʹ�á�\n");

	if((int)me->query_str() < 28)
		return notify_fail("���������,����ʹ����һ����!\n");

	if((int)me->query_skill("kurong-changong",1) < 90)
		return notify_fail("����������Ĺ�����������ʹ��һָǬ��!\n");

	if((int)me->query_skill("sun-finger",1) < 90)
		return notify_fail("���һ��ָ��Ϊ����,Ŀǰ������ʹ��һָǬ������!\n");

	if((int)me->query("max_neili") < 850)
		return notify_fail("��������Ϊ����, ����ʹ��һָǬ��! \n");

	if((int)me->query("neili") < 200)
		return notify_fail("���������ڲ���, ����ʹ��һָǬ��! \n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

	msg = HIY "$Nʹ��һ��ָ������һָǬ��������ס��$n��ȫ��ҪѨ, ʹ$n�������á�\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4 )
	{
		msg +=  HIG "���$p��$P���˸����ֲ���! һʱ���ܶ���! \n" NOR;
		target->start_busy( (int)me->query_skill("sun-finger",1) / 20 + 3);
		me->add("neili", -200);
	}
	else
	{
		msg += HIM "����$p������$P����ͼ����û���ϵ���\n" NOR;
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	return 1;
}
