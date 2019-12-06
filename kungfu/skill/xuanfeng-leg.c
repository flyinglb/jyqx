// xuanfeng-leg.c ����ɨҶ��
// modified by Venus Oct.1997
inherit SKILL;

mapping *action = ({
([      "action" : "$N˫����Σ�����͵ط���һʽ��������ӿ�����ż�ζ�����
��$n��ƨ��",
        "damage" : 100,
        "dodge" : 15,
        "damage_type" : "����",
        "lvl" : 10,
        "skill_name" : "������ӿ"
]),
([      "action" : "$N��Ŷٵأ���ת�����������ߣ�ֻһɲ�Ǽ�һ�����ҽ�һʽ
���չ�������������$n��$l",
        "damage" : 120,
        "dodge" : 10,
        "damage_type" : "����",
        "lvl" : 0,
        "skill_name" : "�չ�����"
]),
([      "action" : "$N����һ��������Ť��ס$n�����֣��ҽ�ͬʱ�߳���������׼��һ
ʽ����Ԩ���ԡ������е�$n���ؿ�",
        "damage" : 140,
        "dodge" : 15,
        "damage_type" : "����",
        "lvl" : 10,
        "skill_name" : "��Ԩ����"
]),
([      "action" : "$NͻȻԾ��˫������Ȧת��һʽ�������Ҷ��������糾������
$n��ȫ��",
        "damage" : 160,
        "dodge" : 15,
        "damage_type" : "����",
        "lvl" : 10,
        "skill_name" : "�����Ҷ"
]),
([      "action" : "$N���ֻ��أ�˫�Ž�������һʽ����ɨ���ơ����ŽŲ���$n����
������",
        "damage" : 180,
        "dodge" : 20,
        "damage_type" : "����",
        "lvl" : 20,
        "skill_name" : "��ɨ����"
]),
([      "action" : "$NͻȻ����ȴ�����ˣ�һ��ǰ�շ����ҽ����϶���һʽ������׹
�ء�����$n������ֱ������",
        "damage" : 200,
        "dodge" : 35,
        "damage_type" : "����",
        "lvl" : 30,
        "skill_name" : "����׹��"
]),
([      "action" : "$Nʹһʽ��˷�紵ѩ����ȫ��ͻȻ������ת��˫���ǰ����Ѹ��
�޼�����$n���ؿ�",
        "damage" : 220,
        "dodge" : 30,
        "damage_type" : "����",
        "lvl" : 40,
        "skill_name" : "˷�紵ѩ"
]),
([      "action" : "$N����Ծ�𣬿������������һ�����ˣ�һʽ���׶����졹��˫��
�����������$n��$l",
        "damage" : 250,
        "dodge" : 35,
        "damage_type" : "����",
        "lvl" : 30,
        "skill_name" : "�׶�����"
]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; } 

int valid_combine(string combo) { return combo=="luoying-zhang"; }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("����ɨҶ�ȱ�����֡�\n");
    if ((int)me->query_skill("bibo-shengong", 1) < 15)
        return notify_fail("��ı̲��񹦻�򲻹����޷�ѧ����ɨҶ�ȡ�\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷�������ɨҶ�ȡ�\n");
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
    level = (int)me->query_skill("xuanfeng-leg", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
       return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
       return notify_fail("�����������������ɨҶ�ȡ�\n");
    me->receive_damage("qi", 20);
    me->add("neili", -1);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"xuanfeng-leg/" + action;
}

