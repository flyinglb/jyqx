// yunlong-zhua.c -����צ

inherit SKILL;

mapping *action = ({
([	"action" : "$Nȫ��εض��𣬰����һ�����һʽ����ӥϮ�á���Ѹ�͵�ץ��$n��$l",
	"force" : 150,
        "dodge" : 15,
        "parry" : 10,
	"damage": 20,
	"lvl" : 0,
	"skills_name" : "��ӥϮ��",
	"damage_type" : "ץ��"
]),
([	"action" : "$N����ֱ����˫��ƽ�죬һʽ����ӥչ�᡹��˫צһǰһ��£��$n��$l",
	"force" : 220,
        "dodge" : 20,
        "parry" : 15,
	"damage": 40,
	"lvl" : 10,
	"skills_name" : "��ӥչ��",
        "damage_type" : "ץ��"
]),
([	"action" : "$Nһʽ���γ�ӥ�ɡ���ȫ����б��ƽ�ɣ�����һ����˫צ����$n�ļ�ͷ",
	"force" : 250,
        "dodge" : 20,
        "parry" : 20,
	"damage": 60,
	"lvl" : 20,
	"skills_name" : "�γ�ӥ��",
        "damage_type" : "����"
]),
([	"action" : "$N˫צ�����Ͼ٣�ʹһʽ��ӭ��������һ�����ֱ�Ϯ��$n����Ҹ����",
	"force" : 290,
        "dodge" : 25,
        "parry" : 20,
	"damage": 80,
	"lvl" : 30,
	"skills_name" : "ӭ������",
        "damage_type" : "����"
]),
([	"action" : "$Nȫ�������ǰ��һʽ��������צ������צͻ�������Ȱ�ץ��$n���ؿ�",
	"force" : 350,
        "dodge" : 30,
        "parry" : 25,
	"damage": 100,
	"lvl" : 40,
	"skills_name" : "������צ",
        "damage_type" : "����"
]),
([	"action" : "$N���ػ��У�һʽ���������ء�������Ϯ�����д�Ѩ�����ַ�ץ$n���ɲ�",
	"force" : 350,
        "dodge" : 35,
        "parry" : 25,
	"damage": 120,
	"lvl" : 50,
	"skills_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N��������צ���棬һʽ���������ա��������������ƿն�����Ѹ���ޱȵػ���$n",
	"force" : 380,
        "dodge" : 55,
        "parry" : 55,
	"damage": 140,
	"lvl" : 60,
	"skills_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N�ڿո߷����ɣ�һʽ��ӥ�����������ж�ʱ�Գ�һ������צӰ����������$n",
	"force" : 430,
        "dodge" : 40,
        "parry" : 40,
	"damage": 160,
	"lvl" : 60,
	"skills_name" : "ӥ������",
        "damage_type" : "����"
]),
([	"action" : "$N���Ĳ��ض���ʹһʽ��������ˮ�������λ���һ����������$n",
	"force" : 470,
        "dodge" : 50,
        "parry" : 50,
	"damage": 180,
	"lvl" : 70,
	"skills_name" : "������ˮ",
        "damage_type" : "����"
]),
([	"action" : "$N΢΢һЦ��ʹһʽ������ڡ���˫�ֻó�������,ֱ����$n��$l",
	"force" : 470,
        "dodge" : 60,
        "parry" : 60,
	"damage": 200,
	"lvl" : 80,
	"skills_name" : "�����",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="unarmed"; }

int valid_combine(string combo) { return combo=="yunlong-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������צ������֡�\n");
	if ((int)me->query_skill("yunlong-shengong", 1) < 50)
		return notify_fail("��������񹦻�򲻹����޷�ѧ����צ��\n");
	if ((int)me->query_skill("force", 1) < 50)
		return notify_fail("��Ļ����ڹ���򲻹����޷�ѧ����צ��\n");
	if ((int)me->query("max_neili") < 350)
		return notify_fail("�������̫�����޷�������צ��\n");
	if ((int)me->query_skill("claw",1) <40)
		return notify_fail("��Ļ���צ����򲻹����޷�ѧ����צ��\n");
	if (5*(int)me->query_skill("yunlong-xinfa",1) <(int)me->query_skill("yunlong-zhua",1))
		return notify_fail("��������ķ���
�򲻹����޷�����ѧ����צ��\n");
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
	level   = (int) me->query_skill("yunlong-zhua",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if( !me->query_skill("yunlong-shengong",1) )
		return notify_fail("��������צ������Ҫ�������ɵ��ڹ���Ϊ������\n");

	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");

	if ((int)me->query("neili") < 20)
		return notify_fail("�������������������צ����\n");

	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if(me->query_skill("yunlong-shengong") > 70 )
	{
		if( random(me->query_skill("yunlong-zhua")) > 30 )
		{
            victim->apply_condition("zhua_poison", random(me->query_skill("yunlong-zhua")/10)
				 + 1 + victim->query_condition("zhua_poison"));
		}
	}
}

string perform_action_file(string action)
{
	return __DIR__"yunlong-zhua/" + action;
}