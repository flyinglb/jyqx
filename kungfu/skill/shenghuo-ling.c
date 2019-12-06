// shenghuo-ling.c ʥ���
// Modified by Venus Oct.1997
// write by Xiang

inherit SKILL;

mapping *action = ({
([  "action": "$N̤��һ���������ڵ���һ�����ѱ�ס��$nС�ȡ�ʮָ��ס��$nС����
�ġ��ж�������������Ѩ��$nֻ���°��������Ѷ������һ��",
    "dodge": -10,
    "damage": 30,
    "damage_type": "����"
]),
([  "action": "ͻȻ֮�䣬$N���λζ���ͬʱ�۽�������$w��$n���ϻ�ȥ�����²�֪���
�ƶ���������䡣����ͬʱץס$n���죬һ��֮�£���$n����ԶԶ���˳�ȥ",
    "dodge": -20,
    "damage": 50,
    "damage_type": "����"
]),
([  "action": "$N����ֱ�������ֳ�$w��$n����������䡣������һ˲֮�䣬$n������
����Ȼһȭ����$n���ϡ�$nһ�����ģ�$N���$w����$n����",
    "dodge": -30,
    "damage": 70,
    "damage_type": "����"
]),
([  "action": "$N���ط��֣������Ǳ�$wβ�����ϵ����ĵ�һ�죬���ô���$n����",
    "dodge": -20,
    "damage": 90,
    "damage_type": "����"
]),
([  "action": "$N��Ȼ��ͷ��һ��ͷ����$nײ����$n������ɫ����������һ�ã�ͻ���ؿ�
һʹ���ѱ�$N����ײ��",
    "dodge": -20,
    "damage": 110,
    "damage_type": "����"
]),
([  "action": "$N��Ȼ��ͷ��һ��ͷ����$nײ����$n������ɫ����������һ�ã�ͻ���ؿ�
$N����$w���Ӻ�ɨ��ͻȻ�����������Ľ��$n��֪�Է��Ǻ����⣬���뻹�Ǳ�֮
Ϊ�������̤��һ������ǰ�׹⼱����$N��$w�ѵ��Ҽ�",
    "dodge": -20,
    "damage": 130,
    "damage_type": "����"
]),
([  "action": "$N��Ȼ��ͷ��һ��ͷ����$nײ����$n������ɫ����������һ�ã�ͻ���ؿ�
һʹ���ѱ�$N����ײ��",
    "dodge": -20,
    "damage": 150,
    "damage_type": "����"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

mapping query_action(object me, object weapon)
{
    if (random(me->query_skill("sword",1)) > 60 &&
        me->query_skill("jiuyang-shengong",1) > 60 &&
        me->query("neili") > 100 &&
        (string)weapon->query("id") == "shenghuo ling" ) {
        me->add("neili", -100);
        return ([
      "action": "$N�������һ����â�������ǰ������ʥ�����໥һ�����һ�죬
$n����һ�������ӴӰ����ֱ��������������в��һ����ʹ���ѱ�$N������һ�š�
���һ�£�$N��ʥ����ȴ�ֻ�����$n��$l",
      "damage": 500,
      "damage_type": "����"]);
    }
    return action[random(sizeof(action))];
}

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("qiankun-danuoyi", 1);

	if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("�����첻�㣬��ѧ��ȥ�����߻���ħ��\n");

	if ((int)me->query("max_neili") < 50)
		return notify_fail("����ô����������ѧʥ�����\n");

        if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
                return notify_fail("��ľ����񹦻�򻹲�����ѧ����ʥ�����\n");

        return 1;
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
            || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("�������������ʥ�����\n");
        me->receive_damage("qi", 40);
        return 1;
}


