// human.c
// From ES2
// Modified by Xiang@XKX

// A normal human is at least 40 kg weight
#define BASE_WEIGHT 40000

inherit F_DBASE;
inherit F_SKILL;

mapping *combat_action = ({
	([	"action":		"$N��ȭ����$n��$l",
		"damage_type":	"����",
	]),
	([	"action":		"$N��$n��$lһץ",
		"damage_type":	"ץ��",
	]),
	([	"action":		"$N��$n��$l�ݺݵ�����һ��",
		"damage_type":	"����",
	]),
	([	"action":		"$N����ȭͷ��$n��$l��ȥ",
		"damage_type":	"����",
	]),
	([	"action":		"$N��׼$n��$l�����ӳ�һȭ",
		"damage_type":	"����",
	]),
});

void create()
{
	seteuid(getuid());
	set("unit", "λ");
	set("gender", "����");
	set("can_speak", 1);
	set("attitude", "peaceful");
	set("limbs", ({
		"ͷ��",	"����",	"�ؿ�",	"����",	"���",	"�Ҽ�",	"���",
		"�ұ�",	"����",	"����",	"����",	"С��",	"����",	"����",
		"���",	"�ҽ�"
	}) );
}

void setup_human(object ob)
{
	mapping my;
	int qi_age;

	my = ob->query_entire_dbase();

	ob->set("default_actions", (: call_other, __FILE__, "query_action" :));
	
	if( undefinedp(my["age"]) ) my["age"] = 14;
	if (undefinedp(my["str"])) my["str"] = 10 + random(21);
	if (undefinedp(my["con"])) my["con"] = 10 + random(21);
	if (undefinedp(my["dex"])) my["dex"] = 10 + random(21);
	if (undefinedp(my["int"])) my["int"] = 10 + random(21);
	if (undefinedp(my["per"])) my["per"] = 10 + random(21);
	if (undefinedp(my["kar"])) my["kar"] = 10 + random(21);

	if( userp(ob) || undefinedp(my["max_jing"]) ) {

		if( my["age"] <= 14 ) my["max_jing"] = 100;
		else if( my["age"] <= 30 ) my["max_jing"] = 100 + (my["age"] - 14) * my["int"];
		else if( my["age"] >= 60 ) my["max_jing"] -= (my["age"] - 60) * 5;
		else my["max_jing"] = my["int"] * 16 + 100;

		//To do about Taoism

		if( my["max_jingli"] > 0 ) my["max_jing"] += my["max_jingli"] / 4;
	}
	if( userp(ob) || undefinedp(my["max_qi"]) ) {
		
		if( my["age"] <= 14 ) my["max_qi"] = 100;
		else if( my["age"] <= 30 ) my["max_qi"] = 100 + (my["age"] - 14) * my["con"];
		else if( my["age"] >= 60 ) my["max_qi"] -= (my["age"] - 60) * 5;
		else my["max_qi"] = my["con"] * 16 + 100;
		
		// ����������������ǰ���������������
		if((qi_age=(int)ob->query_skill("taoism", 1)) > 39);
		{
			qi_age = qi_age/2;
			if (my["age"] <= 30) qi_age -= my["age"];
			else qi_age -= 30;
			
			if (qi_age > 0) my["max_qi"] += qi_age *((int)ob->query_skill("taiji-shengong", 1)/10); 
		}
		
		if( my["max_neili"] > 0 ) my["max_qi"] += my["max_neili"] / 4;
	}

	ob->set_default_object(__FILE__);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 2000);
}

mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}
