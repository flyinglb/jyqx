// 
// fen.c �����Ի�
// by secret
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp;
	int damage;
	int neili_wound, qi_wound ;
	me->clean_up_enemy();
	target = me->select_opponent();
		skill = me->query_skill("huoyan-dao",1);
	if( !(me->is_fighting() ))
		return notify_fail("�������Ի�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("���������˹���\n");
	if( skill < 60)
		return notify_fail("��ġ����浶���ȼ�����, ����ʹ���������Ի𡹣�\n");
	if( me->query("neili") < 150 )
		return notify_fail("��������������޷��˹���\n");
 
	msg = HIC "$N�������ƣ�ʹ��һ�С������Ի𡹣���$n���ؿڻ�ȥ��\n"NOR;
	message_vision(msg, me, target);
	ap = me->query("combat_exp") + skill * 400;
	dp = target->query("combat_exp") / 2;
	if( dp < 1 )
	dp = 1;
	if( random(ap) > dp )
	{
	if(userp(me))
		me->add("neili",-100);
		msg = HIG "$nֻ������ǰһ�ڣ����ۡ���һ�����һ����Ѫ��\n"NOR;
	neili_wound = 100 + random(skill);
	if(neili_wound > target->query("neili"))
		neili_wound = target->query("neili");
		qi_wound = neili_wound / 5;
		damage = (int)me->query_skill("huoyan-dao", 1);
		damage = damage +  0.5 * (int)me->query_skill("force", 1);
		target->receive_damage("qi", damage/5);
		target->receive_wound("qi", damage/5);
		target->add("neili", -neili_wound);
		target->add("qi", -qi_wound);
		target->add("eff_qi",-qi_wound);
		target->start_busy(2);
		me->start_busy(random(2));
	}
	else
	{
		msg = HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
		if(userp(me))
		me->add("neili",-100);
		me->start_busy(4);
	}
	message_vision(msg, me, target);
	return 1;
}