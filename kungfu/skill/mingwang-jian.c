//
// mingwang-jian.c ����������
// Designed by secret(����)
//

inherit SKILL;

mapping *action = ({
([      "action" : "$NŭĿԲ����ʹ��һ�С�������������$wһ����ֱ��$n��$l  ",
        "skill_name" : "����",
        "force" : 100,
        "dodge" : -10,
        "lvl" : 0,
        "damage" : 30,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һʽ�����ֳ�����������һ������â����$n��$l  ",
        "skill_name" : "���ֳ���",
        "force" : 140,
        "dodge" : 5,
        "lvl" : 8,
        "damage" : 30,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�ɽ����������Ծ���գ�$w��ɽ��������$n��$l  ",
        "skill_name" : "ɽ��",
        "force" : 180,
        "dodge" : -10,
        "lvl" : 16,
        "damage" : 40,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ����ǧ��ת������$w�����ĳ�һ�㣬��Ȼһ������$n��$l  ",
        "skill_name" : "ǧ��ת",
        "force" : 220,
        "dodge" : 10,
        "lvl" : 24,
        "damage" : 48,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С���ħ�衹��ȫ��������$w�У�����ֱָ$n��$l  ",
        "skill_name" : "��ħ��",
        "force" : 250,
        "dodge" : 10,
        "lvl" : 32,
        "damage" : 54,
        "damage_type" : "����",
]),
([      "action" : "$N���������ʹ��һʽ�����衹��һ���������Ӱ����$n��$lɨȥ  ",
        "skill_name" : "����",
        "force" : 280,
        "dodge" : 15,
        "lvl" : 40,
        "damage" : 60,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С����ڡ�������$w������������$n��$l  ",
        "skill_name" : "����",
        "force" : 300,
        "dodge" : 20,
        "lvl" : 48,
        "damage" : 66,
        "damage_type" : "����",
]),
([      "action" : "$N����һԾ���Ӹ�����ʹ�����������졹����ʱ�����������$n��$l  ",
        "skill_name" : "��������",
        "force" : 320,
        "dodge" : 25,
        "lvl" : 80,
        "damage" : 80,
        "damage_type" : "����",
]),
});


int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_combine(string combo) { return combo=="xue-dao"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("longxiang", 1) >= 20 ||
	    (int)me->query_skill("xiaowuxiang", 1) >= 20)
		return 1;
	else if ((int)me->query_skill("longxiang", 1) < 20)
		return notify_fail("���������������̫ǳ��\n");
	else if ((int)me->query_skill("xiaowuxiang", 1) < 20)
		return notify_fail("���С���๦���̫ǳ��\n");
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
	level   = (int) me->query_skill("mingwang-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("������������������˲�����������\n");
	me->receive_damage("qi", 20);
	return 1;
}
string perform_action_file(string action)
{
    return __DIR__"mingwang-jian/" + action;
}
