// hua.c 化骨绵掌

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
//        object weapon;
	string msg;

	if( !target ) target = offensive_target(me);

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不能攻击别人! \n");

	if( !target || !target->is_character() )
		return notify_fail("辣手化骨只能对对手使用。\n");

	if( (int)me->query_skill("shenlong-xinfa", 1) < 50 )
		return notify_fail("你的神龙心法不够娴熟，不能化骨。\n");

	if( (int)me->query_skill("huagu-mianzhang", 1) < 40 )
		return notify_fail("你的化骨绵掌不够娴熟，不能化骨。\n");

	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("你的内力不够，不能化骨。\n");

        me->add("neili", -100);

	msg = MAG "$N掌出如风轻轻落在$n肩头上。\n"NOR;

	me->start_busy(1);
	if( random( (int)me->query_skill("huagu-mianzhang",1))
          > random(target->query_skill("dodge"))/2 )
        {
		msg += MAG "结果只听扑的一声，$p被$P一掌拍中！\n" NOR;
		msg += MAG "$p只觉得全身暖洋洋的，感到有点轻飘无力轻。\n" NOR;
		target->add_temp("apply/attack", -1);
		target->add_temp("apply/dodge", -1);
		target->add_temp("apply/defense", -1);
	} else {
		msg += CYN"可是$p急忙闪在一旁，躲了开去。\n" NOR;
		me->start_busy(3);
	}
	message_vision(msg, me, target);
	if( !target->is_fighting(me) ) target->fight_ob(me);
	return 1;
}
