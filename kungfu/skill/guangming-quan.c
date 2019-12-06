// guangming-quan - �����ȭ��

inherit SKILL;

mapping *action = ({
([	"action" : "$Nһʽ�����Ҳ�������������Σ���������ͻȻ����$n��$l",
	"force" : 100,
        "dodge" : 10,
	"lvl" : 0,
	"skill_name" : "���Ҳ���",
	"damage_type" : "����"
]),
([	"action" : "$Nһʽ������ʥ�𡹣�ʮָ�ſ���������ǰ�����������֮״������$n",
	"force" : 110,
        "dodge" : 10,
        "parry" : 10,
        "damage" : 10,
	"lvl" : 10,
	"skill_name" : "����ʥ��",
	"damage_type" : "����"
]),
([	"action" : "$N����һ�Σ�һʽ������λ�������������$n�ļ�ͷ����ȭ����$n���ؿ�",
	"force" : 120,
        "dodge" : 15,
        "damage" : 15,
	"lvl" : 20,
	"skill_name" : "����λ�",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ������οࡹ�����ֻ�£��צ��һ���־����$n���ʺ�Ҫ��",
	"force" : 130,
        "dodge" : 20,
	"damage": 15,
	"lvl" : 30,
	"skill_name" : "����ο�",
        "damage_type" : "����"
]),
([	"action" : "$N�������У�����ֱ����һʽ��Ϊ�Ƴ��񡹣���Ʈ��������$n������",
	"force" : 160,
        "dodge" : 20,
	"damage": 20,
	"lvl" : 40,
	"skill_name" : "Ϊ�Ƴ���",
        "damage_type" : "����"
]),
([	"action" : "$Nʹһʽ��Ω�����ʡ�����ȭ�ϸ�����̽��ͻ����ץ��$n��$l",
	"force" : 200,
        "dodge" : 30,
	"damage": 25,
	"lvl" : 50,
	"skill_name" : "Ω������",
        "damage_type" : "����"
]),
([	"action" : "$N˫ȭ���裬һʽ��ϲ�ֱ�������ֻ��ۣ�£��Ȧ״���ͻ�$n�����",
	"force" : 250,
        "dodge" : 30,
	"damage": 30,
	"lvl" : 56,
	"skill_name" : "ϲ�ֱ���",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ���Թ鳾������ʮָ����������ʵʵ��Ϯ��$n��ȫ��ҪѨ",
	"force" : 310,
        "dodge" : 40,
	"damage": 35,
	"lvl" : 62,
	"skill_name" : "�Թ鳾��",
        "damage_type" : "����"
]),
([	"action" : "$N˫�ֱ�ȭ��һʽ���������ˡ�����Ӱ���ɣ�ͬʱ��$nʩ���žŰ�ʮһ��",
	"force" : 380,
        "dodge" : 40,
	"damage": 40,
	"lvl" : 68,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ���ǻ�ʵ�ࡹ��ȭ���������֣��������ޣ�����������$n�ĵ���",
	"force" : 460,
        "dodge" : 40,
	"damage": 50,
	"lvl" : 74,
	"skill_name" : "�ǻ�ʵ��",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������ȭ������֡�\n");
	if ((int)me->query_skill("sunforce", 1) < (int)me->query_skill("guangming-quan", 1) 
		&& me->query_skill("guangming-quan", 1) > 60 )
		return notify_fail("��Ĺ����񹦻�򲻹����޷�ѧ������Ĵ����ȭ��\n");
	if ((int)me->query("max_force") < 100)
		return notify_fail("�������̫�����޷��������ȭ��\n");
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
	level   = (int) me->query_skill("guangming-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[random(i)];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("force") < 20)
		return notify_fail("������������������ȭ��\n");
	me->receive_damage("kee", 25);
	me->add("force", -5);
	return 1;
}

int enable_factor() { return 15; }

int learn_bonus() { return 15; }

int practice_bonus() { return 13; }

int study_bonus() { return 15; }