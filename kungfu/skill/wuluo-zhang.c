// wuluo-zhang.c ����������

inherit SKILL;

mapping *action = ({
([  "action" : "$N��Ϣ����������һ�ơ��������������������������$n",
    "force"  : 130,
    "dodge"  : 20,
	"damage" : 0,
    "lvl"    : 0,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([  "action" : "$N����ǳЦ���Ƶ�$n�����������������ӵ$n���䡣$n��
ü���㣬$N����һ�С��������ơ���������Ϣ��$n��$l�ĵ�",
    "force"  : 150,
    "dodge"  : 20,
	"damage" : 30,
    "lvl"    : 20,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([  "action" : "$Nһ�С��̺����Ρ���˫�ƻû���һƬ��Ӱ����һ�����̣�
��$nϸϸ���ܵ���������",
    "force"  : 150,
    "dodge"  : 30,
	"damage" : 45,
    "lvl"    : 40,
	"skill_name" : "�̺�����",
	"damage_type" : "����"
]),

([  "action" : "$N����Խ��Ȧ�⣬����һ�С��������졹��ԶԶ����$n��$l
�����ĳ����ƣ��Ʒ�ε�����Ȼ��ʢֱ��$n����������",
    "force"  : 200,
    "dodge"  : 25,
	"damage" : 55,
    "lvl"    : 60,
	"skill_name" : "��������",
    "damage_type" : "����"
]),
([  "action" : "$N���ƴ�������Χ��������ƮƮ����$n��ȥ������$n������
�ܣ�����ȴ���ؿڼ���Ȧ����һ�С��������������ϳ����ƣ�����$n��$l",
    "force"  : 250,
    "dodge"  : 70,
	"damage" : 10,
    "lvl"    : 80,
	"skill_name" : "��������",
    "damage_type" : "����"
]),
([  "action" : "$N˫�����ƣ�����һ�󾢷磬һ�С�������ɢ����һ�ɿ���
����$n",
    "force"  : 300,
    "dodge"  : 20,
	"damage" : 90,
    "lvl"    : 100,
	"skill_name" : "������ɢ",
    "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="jinyu-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����������Ʊ�����֡�\n");
	if ((int)me->query_skill("kurong-changong",1) < 20)
		return notify_fail("��Ŀ�������̫�����޷������������ơ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷������������ơ�\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
    level = (int) me->query_skill("wuluo-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("����������������������ơ�\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}


