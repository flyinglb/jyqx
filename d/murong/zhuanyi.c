// xingyi.c ��ת����perform���ƶ�ת

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
        string msg;
        object weapon;

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ƶ�תֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("douzhuan-xingyi", 1) < 119 )
		return notify_fail("������ƶ�ת��δ���ɣ�����ʹ�ã�\n");

        if( (int)me->query("neili", 1) < 500 )
		return notify_fail("�������������㣬����ʹ�����ƶ�ת��\n");	

	if( (int)me->query_skill("parry", 1) < 119 )
		return notify_fail("��Ļ����м�֮��������죬����ʹ�����ƶ�ת��\n");

    msg = HIY "\n��Ȼ���ذ���$Nʹ��$n���У������������ڼ�������$N��ȥ��\n"NOR;

	if( weapon = target->query_temp("weapon") ){
        if( random(me->query("str")) > (int)target->query("str")*2/3 ) {  
    msg += HIY"\n$pֻ����ȫ���ܵ������𵴣����İ��ʹ��һ����Ѫ���������"
                + target->query_temp("weapon")->query("name") + "׹�ض�����\n" NOR;
		message_vision(msg, me, target);
		(target->query_temp("weapon"))->move(environment(target));
                me->add("neili", -400);
	} else {
    msg += HIY"\n$p��ôҲ�벻��$N�ܹ�ʹ���Լ��ĳ���������Σ��֮��˫�Űϵض��𣬼��ѵĶ����һ�У���ɫ��Ĳ԰ס�\n" NOR;
		message_vision(msg, me, target);
	}
	me->start_busy(1);
        }
        else
        {
        if (random(me->query_skill("parry")) > target->query_skill("parry")*2/3 )
	{
		me->start_busy(3);
		target->start_busy(random(3));
		
		damage = (int)me->query_skill("shenyuan-gong", 1);
		
		damage = damage*4 + random(damage);
		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		me->add("neili", -400);
		
		if( damage < 300 ) msg += HIY"\n���$n��ɫ��òҰף������������˺ü�����\n"NOR;
        	else if( damage < 400 ) msg += HIY"\n������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n"NOR;
        	else if( damage < 500 ) msg += RED"\n������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n"NOR;
        	else msg += HIR"\n���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n"NOR;
		
	} else 
	{
		me->start_busy(1);
    msg += HIY"\n$p��ôҲ�벻��$N�ܹ�ʹ���Լ��ĳ���������Σ��֮��˫�Űϵض��𣬼��ѵĶ����һ�У���ɫ��Ĳ԰ס�\n" NOR;
	}
	message_vision(msg, me, target);

        }
	return 1;
}

