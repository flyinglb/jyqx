// tiandi.c ��ر�ɫ

#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h"

int perform(object me, object target)
{
	string msg;
	object weapon;
	int damage, p;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("��ر�ɫֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query_skill("canhe-zhi", 1) < 100 )
		return notify_fail("��Ĳκ�ָ������죬�޷�ʹ����ر�ɫ��\n");

	weapon = me->query_temp("weapon");
	if (weapon) return notify_fail("��ر�ɫ�����ʹ�á�\n");

	if ( (int)me->query("neili") < 400)
		return notify_fail("��������������޷�ʹ����ر�ɫ��\n");

	msg = CYN "$Nʹ���κ�ָ��ر�ɫ����ָͻ��һ��������������һ�ɣ������С�������ֱϮ$nǰ�ء�\n";

	damage = (int)me->query_skill("canhe-zhi", 1) + (int)me->query_skill("shenyuan-gong", 1) + 100;
	damage += random(damage / 2);
	if (random(me->query("combat_exp")) > (int)target->query("combat_exp") / 3) {
		msg += "$n�������������ۡ���һ������ָ������ǰ�أ�\n";
                target->receive_damage("qi", damage/2);
		target->receive_wound("qi", damage / 3);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
		msg += RED "$n�ؿ�һ���ʹ��ָ�������ؿڣ�\n"NOR ;
//                msg += damage_msg(damage, "����");
//                msg += "( $n" + eff_status_msg(p) + " )\n";
	} 
	else if (random(me->query("combat_exp")) > (int)target->query("combat_exp") * 2 / 3) {
		msg += "$n���Ա�һ�����ù��˾��磬û�뵽���ָ����Ȼ�л�������$n����ת������������$p�ĺ󱳡�\n";
		target->receive_damage("qi", damage / 3);
		target->receive_wound("qi", damage / 9);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
		msg += RED "$n�����ؿ��е�ʹ��\n"NOR ;
//                msg += damage_msg(damage, "����");
//              msg += "( $n" + eff_status_msg(p) + " )\n";
	}
	else {
		msg += "$n���Ա�һ�����ù��˾��磬��æ��ֻ��һ��ǰ�˲ſ��������ģ���Ǳ�֮����\n" NOR;
	}
	message_vision(msg, me, target);
	me->add("neili", -300);
        me->start_busy(2);

	return 1;
}

