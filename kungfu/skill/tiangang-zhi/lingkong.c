// lingxiao.c ���ָѨ�� �����ָѨ��

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if((int)me->query_str() < 25)
		return notify_fail("���������,����ʹ����һ����!\n");

	if((int)me->query_skill("linji-zhuang",1) < 100)
		return notify_fail("���ټ�ʮ��ׯ�Ĺ�����������ʹ�����ָѨ!\n");

	if((int)me->query_skill("finger") < 100)
		return notify_fail("���ָ����Ϊ����,Ŀǰ������ʹ�����ָѨ����!\n");

	if((int)me->query("neili") < 300)
		return notify_fail("���������ڲ���, ����ʹ�����ָѨ! \n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

	msg = 
HIY "$Nʹ�����ָѨ�����������ָѨ�����ع������������������۾�һ�㣬��
��ʳ�ж�ָ��$n������ȥ��һ����ָ��ȫ�Ƕ���$n��ͷ����ǰ����Ѩ��$n��
�����У�ƴ�����$Nָ����ʱ�������ҡ�\n";
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4 )
	{
		msg +=  HIG "���$p��$Pָ�����м���Ѩ��! \n" NOR;
                target->start_busy( (int)me->query_skill("tiangang-zhi",1) / 30 + 2);
		me->add("neili", -100);
                me->start_busy(1);
	}
	else
	{
		msg += HIM "$p�鼱����������һԾ���˳���Զ��\n" NOR;
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	return 1;
}
