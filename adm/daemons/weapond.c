// weapond.c

#include <ansi.h>
#include <combat.h>

mapping weapon_actions = ([
	"slash": ([
		"damage_type":	"����",
		"action":		"$N�Ӷ�$w��ն��$n��$l",
		"parry":		20,
		]),
	"slice": ([
		"damage_type":	"����",
		"action":		"$N��$w��$n��$l��ȥ",
		"dodge":		20,
		]),
	"chop": ([
		"damage_type":	"����",
		"action":		"$N��$w����$n��$l������ȥ",
		"parry":		-20,
		]),
	"hack": ([
		"action":		"$N����$w����׼$n��$lһ���ҿ�",
		"damage_type":	"����",
		"damage":		30,
		"dodge":		30,
		]),
	"thrust": ([
		"damage_type":	"����",
		"action":		"$N��$w��$n��$l��ȥ",
		"dodge":		15,
		"parry":		-15,
		]),
	"pierce": ([
		"action":		"$N��$w��$n��$l�ݺݵ�һͱ",
		"damage_type":	"����",
		"dodge":		-30,
		"parry":		-30,
		]),
	"whip": ([
		"action":		"$N��$wһ���$n��$l��ȥ",
		"damage_type":	"����",
		"dodge":		-20,
		"parry":		30,
		]),
	"impale": ([
		"action":		"$N��$w��$n��$lֱ����ȥ",
		"damage_type":	"����",
		"dodge":		-10,
		"parry":		-10,
		]),
	"bash": ([
		"action":		"$N����$w����$n��$l����һ��",
		"damage_type":	"����",
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
		]),
	"crush": ([
		"action":		"$N�߸߾���$w����$n��$l��ͷ����",
		"damage_type":	"����",
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
		]),
	"slam": ([
		"action":		"$N����$w����¶�׹⣬�͵ض�׼$n��$l���˹�ȥ",
		"damage_type":	"����",
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
		]),
	"throw": ([
		"action":		"$N��$w��׼$n��$l���˹�ȥ",
		"damage_type":	"����",
		"post_action":	(: call_other, __FILE__, "throw_weapon" :),
		]),
]);

varargs mapping query_action()
{
	string verb, *verbs;

	verbs = previous_object()->query("verbs");

	if( !pointerp(verbs) ) return weapon_actions["hit"];
	else {
		verb = verbs[random(sizeof(verbs))];
		if( !undefinedp(weapon_actions[verb]) ) return weapon_actions[verb];
		else return weapon_actions["hit"];
	}	
}

void throw_weapon(object me, object victim, object weapon, int damage)
{
	if( objectp(weapon) ) {
		if( (int)weapon->query_amount()==1 ) {
			weapon->unequip();
			tell_object(me, "\n���" + weapon->query("name") + "�����ˣ�\n\n");
		}
		weapon->add_amount(-1);
	}
}

void bash_weapon(object me, object victim, object weapon, int damage)
{
	object ob;
	int wap, wdp;

	if( objectp(weapon)
	&&	damage==RESULT_PARRY
	&&	ob = victim->query_temp("weapon") ) {
		wap = (int)weapon->weight() / 500
			+ (int)weapon->query("rigidity")
			+ (int)me->query("str");
		wdp = (int)ob->weight() / 500
			+ (int)ob->query("rigidity")
			+ (int)victim->query("str");
		wap = random(wap);
		if( wap > 2 * wdp ) {
			message_vision(HIW "$Nֻ��������" + ob->name() + "�ѳֲ��������ַɳ���\n" NOR,
				victim);
			ob->unequip();
			ob->move(environment(victim));
			victim->reset_action();
		} else if( wap > wdp ) {
			message_vision("$Nֻ��������" + ob->name() + "һ����Щ���֣�\n",
				victim);
		} else if( wap > wdp / 2 ) {
			message_vision(HIW "ֻ������ž����һ����$N���е�" + ob->name()
				+ "�Ѿ���Ϊ���أ�\n" NOR, victim );
			ob->unequip();
			ob->move(environment(victim));
			ob->set("name", "�ϵ���" + ob->query("name"));
//			ob->set("value", (int)ob->query("value") / 10);
			ob->set("value", 0);
			ob->set("weapon_prop", 0);
			victim->reset_action();
		} else {
			message_vision("$N��" + weapon->name() + "��$n��" + ob->name()
				+ "�����ð�����Ļ��ǡ�\n", me, victim);
		}
	}
}
