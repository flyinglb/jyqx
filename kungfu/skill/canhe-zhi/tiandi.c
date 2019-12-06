// tiandi.c 天地变色

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
		return notify_fail("天地变色只能对战斗中的对手使用。\n");

	if( (int)me->query_skill("canhe-zhi", 1) < 100 )
		return notify_fail("你的参合指不够娴熟，无法使用天地变色。\n");

	weapon = me->query_temp("weapon");
	if (weapon) return notify_fail("天地变色须空手使用。\n");

	if ( (int)me->query("neili") < 400)
		return notify_fail("你的内力不够，无法使用天地变色。\n");

	msg = CYN "$N使出参合指天地变色，中指突地一弹，两道劲风汇成一股，“咝咝”有声，直袭$n前胸。\n";

	damage = (int)me->query_skill("canhe-zhi", 1) + (int)me->query_skill("shenyuan-gong", 1) + 100;
	damage += random(damage / 2);
	if (random(me->query("combat_exp")) > (int)target->query("combat_exp") / 3) {
		msg += "$n躲闪不及，“噗”地一声，被指劲击中前胸！\n";
                target->receive_damage("qi", damage/2);
		target->receive_wound("qi", damage / 3);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
		msg += RED "$n胸口一阵巨痛，指劲正击胸口！\n"NOR ;
//                msg += damage_msg(damage, "刺伤");
//                msg += "( $n" + eff_status_msg(p) + " )\n";
	} 
	else if (random(me->query("combat_exp")) > (int)target->query("combat_exp") * 2 / 3) {
		msg += "$n向旁边一闪，让过了劲风，没想到这股指劲竟然有回力，从$n背后倒转回来，正刺中$p的后背。\n";
		target->receive_damage("qi", damage / 3);
		target->receive_wound("qi", damage / 9);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
		msg += RED "$n觉的胸口有点痛！\n"NOR ;
//                msg += damage_msg(damage, "刺伤");
//              msg += "( $n" + eff_status_msg(p) + " )\n";
	}
	else {
		msg += "$n向旁边一闪，让过了劲风，匆忙中只好一个前扑才堪堪躲过，模样狼狈之极。\n" NOR;
	}
	message_vision(msg, me, target);
	me->add("neili", -300);
        me->start_busy(2);

	return 1;
}

