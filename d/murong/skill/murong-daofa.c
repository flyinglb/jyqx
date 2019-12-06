// murong-daofa.c Ľ�ݵ���

inherit SKILL;

mapping *action = ({
([	"action" : "$N���һ�������С���һ�С�����ǵ���׳־�����������϶�����$n��$l��ȥ",
	"force" : 180,
        "dodge" : 10,
        "parry" : 10,
	"damage": 30,
	"lvl" : 20,
	"skill_name" : "����ǵ���׳־",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С��䵶��ת��Ǭ����������$w�ڿ��м���ת����Ȧ������$n��$l",
	"force" : 260,
        "dodge" : 10,
        "parry" : 10,
	"damage": 70,
	"lvl" : 40,
	"skill_name" : "�䵶��ת��Ǭ��",
	"damage_type" : "����"
]),
([	"action" : "$N��һ����һ�С�ң����ǧ��ѩ��,$wֱ��$n�ľ���նȥ",
	"force" : 320,
        "dodge" : 5,
        "parry" : 5,
	"damage": 120,
	"lvl" : 60,
	"skill_name" : "ң����ǧ��ѩ",
	"damage_type" : "����",
]),
([	"action" : "$Nһ�С�׳־���������������������⻯����㷱�ǣ���$n��$l��ȥ",
	"force" : 380,
        "dodge" : 10,
        "parry" : 5,
	"damage": 150,
	"lvl" : 80,
	"skill_name" : "׳־����������",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_combine(string combo) { return combo=="murong-jianfa"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("shenyuan-gong", 1) < 10)
		return notify_fail("�����Ԫ�����̫ǳ��\n");
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
	level   = (int) me->query_skill("murong-daofa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 40)
		return notify_fail("�������������Ľ�ݵ�����\n");
	me->receive_damage("jingli", 35);
	return 1;
}


