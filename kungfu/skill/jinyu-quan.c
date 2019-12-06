// jinyu-quan.c ����ȭ

inherit SKILL;

mapping *action = ({
([	"action" : "$Nһ�С������á���˫ȭһ��һ��, ��$n��ȥ",
	"force"  : 120,
	"dodge"  : 10,
	"damage" : 20,
	"lvl"    : 0,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С������Ͻ𡹣��ó�һƬȭӰ��������磬����$n��ͷ��",
	"force"  : 140,
	"dodge"  : 20,
	"damage" : 30,
	"lvl"    : 20,
	"skill_name" : "�����Ͻ�",
	"damage_type" : "����"
]),
([	"action" : "$N��Ӱ����Ʈ������΢Ц��һ�С��������񡹣���������$n��$l",
	"force"  : 150,
	"dodge"  : 20,
	"damage" : 45,
	"lvl"    : 40,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С��������⡹��˫ȭһ�ϣ�$nֻ��������$N��ȭӰ",
	"force"  : 160,
	"dodge"  : 25,
	"damage" : 60,
	"lvl"    : 60,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N����$nһת���������ߣ�ȭ����磬��������$n������һ��
���������á�",
	"force"  : 170,
	"dodge"  : 30,
	"damage" : 60,
	"lvl"    : 80,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "ֻ��$Nһ�������˲���������Σ�ͻȻ�Ϳ��������ѵ�$n��ǰ��
��ȭ���������Ⱦ������ף�Ѹ����ף�һ�С���ʯ�ɽ𡹻���$n��ǰ��",
	"force"  : 180,
	"dodge"  : 35,
	"damage" : 80,
	"lvl"    : 100,
	"skill_name" : "��ʯ�ɽ�",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С��ڿ���𡹣�����$n���ƺ�$n��ȫ����ȭӰ����",
	"force"  : 280,
	"dodge"  : 30,
	"damage" : 100,
	"lvl"    : 120,
	"skill_name" : "�ڿ����",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_combine(string combo) { return combo=="wuluo-zhang"; }

int valid_learn(object me)
{
    if ((int)me->query_skill("kurong-changong",1) < 20)
		return notify_fail("��Ŀ���������򲻹����޷�������ȭ��\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ȭ������֡�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�������ȭ��\n");
	return 1;
}
mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("jinyu-quan",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�����������������ȭ��\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}


