// kuangfeng.c  ������

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object ob;
        string msg;
 
	if( !me->is_fighting() )
		return notify_fail("����������ֻ����ս����ʹ�á�\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������������ʼʱ�������ű�����\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("�������������\n");

	if( (int)me->query_skill("bibo-shengong",1) < 50 )
		return notify_fail("��ı̲��񹦲�����\n");

	if( (int)me->query_skill("luoying-zhang",1) < 100 ||
	    me->query_skill("xuanfeng-leg",1) < 100)
		return notify_fail("������ƹ��򻹲����ң��޷�ʹ�ÿ�������\n");

	msg = HIY "$Nʹ���һ�����������������������Ȼ�ӿ죡\n" NOR;
	message_vision(msg, me);

	me->clean_up_enemy();
	ob = me->select_opponent();

	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

	me->add("neili", -100);
	me->start_busy(2);

	if(!ob->is_fighting(me)) ob->fight_ob(me);
	return 1;
}
