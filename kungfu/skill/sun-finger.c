// sun-finger.c һ��ָ book: һ��ָ��

inherit SKILL;

mapping *action = ({
([	"action" : "$Nһʽ��������������������ָ���籡������������ָ�������
��������$n��$l",
	"force" : 100,
	"dodge" : 25,
	"damage": 10,
	"lvl" : 0,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N����һת��һ���絽$n���$n��æת��$N���������Ծ�أ�
һʽ��³�����ա�������ʳָ������ָ��$n��$l",
	"force" : 120,
	"dodge" : 25,
	"damage": 20,
	"lvl" : 20,
	"skill_name" : "³������",
	"damage_type" : "����"
]),
([	"action" : "$N����̤��һ���������������ʳָЮ���ۻ���������$n��$l��
��ʽ����̹��������һʽ��������ѩ��",
	"force" : 160,
	"dodge" : 20,
	"damage": 40,
	"lvl" : 40,
	"skill_name" : "������ѩ",
	"damage_type" : "����"
]),
([	"action" : "$N��ӰƮ��һʽ���������졹�����϶��£���������繳����
��$n���Ҽ磬$n������ܣ�$N���ֳ��Ƶ���$n��$l",
	"force" : 190,
	"dodge" : 30,
	"damage": 50,
	"lvl" : 60,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "ֻ��$N���Ϻ���һ�죬����һ�գ�һʽ�����ս�����������ʳָ
бָ����$n��$l��ȥ",
	"force" : 220,
	"dodge" : 30,
	"damage": 70,
	"lvl" : 70,
	"skill_name" : "���ս���",
	"damage_type" : "����"
]),
([	"action" : "$N����б����ͻȻ�����Ϊָ���͵�һ���죬һʽ�����ﳯ������
ʹ��һ��ָ��������$n��$l",
	"force" : 250,
	"dodge" : 20,
	"damage": 80,
	"lvl" : 90,
	"skill_name" : "���ﳯ��",
	"damage_type" : "����"
]),
([	"action" : "$N����һԾ������$n������ϥһ��������ʳָ����һʽ����
������������$n�ĺ���",
	"force" : 280,                                                  
	"dodge" : 25,
	"damage": 100,
	"lvl" : 100,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([  "action" : "$Nһ�����, һʽ��������̩�����þ�ȫ����$n��$l��ȥ",
	"force" : 300,
	"dodge" : 10,
	"damage": 120,
	"lvl" : 130,
	"skill_name" : "������̩",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_combine(string combo) { return combo=="haotian-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��һ��ָ������֡�\n");
	if (me->query("gender") != "����")
		return notify_fail("���������㣬�޷�ѧһ��ָ��\n");
	if ((int)me->query("max_neili") < 700)
		return notify_fail("�������̫�����޷���һ��ָ��\n");
	if ((int)me->query_skill("kurong-changong", 1) > 80 ||
	    (int)me->query_skill("xiantian-qigong", 1) > 80)
		return 1;
	else
		return notify_fail("��ı����ڹ���򲻹����޷�ѧһ��ָ��\n");
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
	level   = (int) me->query_skill("sun-finger", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("�������������һ��ָ!\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"sun-finger/" + action;
}
