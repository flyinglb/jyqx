// guangming-jian - ���������

inherit SKILL;

mapping *action = ({
([	"action" : "$Nһʽ������ʥ�𡹣�����ƽָ��������磬һ���ǳɺ�ɨ$n������",
	"force" : 120,
        "dodge" : -10,
	"damage" : 25,
	"lvl" : 0,
	"skill_name" : "����ʥ��",
	"damage_type" : "����"
]),
([	"action" : "$N��ǰԾ��һ�������ֽ���������$wʹ��һʽ�����Ҳ�����ֱ��$n��$l",
	"force" : 140,
        "dodge" : -10,
	"damage" : 30,
	"lvl" : 10,
	"skill_name" : "���Ҳ���",
	"damage_type" : "����"
]),
([	"action" : "$N�趯$w��һ�С��������ˡ�Ю��������������$n��$l",
	"force" : 170,
        "dodge" : 5,
	"damage" : 35,
	"lvl" : 20,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$Nһʽ������鳾����$w������һ���һ���󻡣���$n��$l��ȥ",
	"force" : 190,
        "dodge" : 5,
	"damage" : 40,
	"lvl" : 30,
	"skill_name" : "����鳾",
	"damage_type" : "����"
]),
([	"action" : "$N����š���������鱧��Բ��һʽ������λ�����$w�й�ֱ��������$n���ؿ�",
	"force" : 240,
        "dodge" : 10,
	"damage" : 50,
	"lvl" : 40,
	"skill_name" : "����λ�",
	"damage_type" : "����"
]),
([	"action" : "$Nһʽ������οࡹ��$w������������������ֱ����Ю����֮����Ȼն��$n��$l",
	"force" : 280,
        "dodge" : 5,
	"damage" : 60,
	"lvl" : 49,
	"skill_name" : "����ο�",
	"damage_type" : "����"
]),
([	"action" : "$N����ʩ�����������ˡ���$w����Ƴ�һ����â��������ƿ�����$n��$l",
	"force" : 350,
        "dodge" : 5,
	"damage" : 75,
	"lvl" : 57,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N˫�Ȱ�����ף�һʽ�����¹����������⻮������ԲȦ����������������",
	"force" : 400,
        "dodge" : 5,
	"damage" : 90,
	"lvl" : 64,
	"skill_name" : "���¹���",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "sword" || usage == "parry"); }

int valid_learn(object me)
{
	object ob;

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");
	if ((int)me->query("max_force") < 150)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("sunforce", 1) < (int)me->query_skill("guangming-jian", 1) 
		&& me->query_skill("guangming-quan", 1) > 60 )
		return notify_fail("��Ĺ����񹦻�򲻹����޷�ѧ������Ĵ����������\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;

	level   = (int) me->query_skill("guangming-jian",1);
	for(i = sizeof(action); i > 0; i--)
	if(level > action[i-1]["lvl"])
		return action[random(i)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("������������������������\n");
	me->receive_damage("kee", 35);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if(random(2))	return;

	if((int)me->query_skill("guangming-jian", 1) < 60
	|| me->query("combat_exp") < 100000)	return;

	me->reset_action();

	COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
}

int enable_factor() { return 17; }

int learn_bonus() { return 14; }

int practice_bonus() { return 13; }

int study_bonus() { return 14; }