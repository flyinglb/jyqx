// hua.c ��������

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
//        object weapon;
	string msg;

	if( !target ) target = offensive_target(me);

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ�ܹ�������! \n");

	if( !target || !target->is_character() )
		return notify_fail("���ֻ���ֻ�ܶԶ���ʹ�á�\n");

	if( (int)me->query_skill("shenlong-xinfa", 1) < 50 )
		return notify_fail("��������ķ�������죬���ܻ��ǡ�\n");

	if( (int)me->query_skill("huagu-mianzhang", 1) < 40 )
		return notify_fail("��Ļ������Ʋ�����죬���ܻ��ǡ�\n");

	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("����������������ܻ��ǡ�\n");

        me->add("neili", -100);

	msg = MAG "$N�Ƴ������������$n��ͷ�ϡ�\n"NOR;

	me->start_busy(1);
	if( random( (int)me->query_skill("huagu-mianzhang",1))
          > random(target->query_skill("dodge"))/2 )
        {
		msg += MAG "���ֻ���˵�һ����$p��$Pһ�����У�\n" NOR;
		msg += MAG "$pֻ����ȫ��ů����ģ��е��е���Ʈ�����ᡣ\n" NOR;
		target->add_temp("apply/attack", -1);
		target->add_temp("apply/dodge", -1);
		target->add_temp("apply/defense", -1);
	} else {
		msg += CYN"����$p��æ����һ�ԣ����˿�ȥ��\n" NOR;
		me->start_busy(3);
	}
	message_vision(msg, me, target);
	if( !target->is_fighting(me) ) target->fight_ob(me);
	return 1;
}
