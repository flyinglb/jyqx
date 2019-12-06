// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ƽ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����ƽ�����ֻ�ܿ���ʹ�á�\n");		

	if( (int)me->query_skill("tiezhang-zhangfa", 1) < 50 )
		return notify_fail("��������Ʒ�������죬���������ƽ�����\n");

	if( (int)me->query_skill("guiyuan-tunafa", 1) < 60 )
		return notify_fail("��Ĺ�Ԫ���ɷ�������죬����ʹ�����ƽ�����\n");

	extra = me->query_skill("tiezhang-zhangfa",1) / 20;
	extra += me->query_skill("guiyuan-tunafa",1) /20;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIR  "$N����۹�Ԫ���ɷ��ݣ�ͬʱʹ�������ƽ�����һ��һ����������糱ˮ��Ļ���$n��" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  HIW "$Nʹ�������ƽ�����һ��һ����������糱ˮ��Ļ���\n" NOR;
        message_vision(msg, me, target);
	for(i=0;i<extra/4;i++)
	{
        msg = HIC "ʹ�������ƽ�����һ��һ����������糱ˮ��Ļ���\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
        me->add("neili", -100);
	me->start_busy(4);
	return 1;
}

