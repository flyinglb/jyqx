// duanjia-sword.c �μҽ�

inherit SKILL;

mapping *action = ({
([  "action" : "$N��ǰ����һ����һ�С��ƺ����롹������$w����������$n��$l
������ȥ",
    "force" : 100,
    "dodge" : 20,
    "damage" : 25,
    "lvl" : 0,
    "skill_name" : "�ƺ�����",
    "damage_type" : "����"
]),
([  "action" : "$N����Ծ�����ֽ���������һ����$w�����������٣�һʽ������
ֱ�¡�ֱ��$n��$l",
    "force" : 120,
    "dodge" : 15,
    "damage" : 30,
    "lvl" : 9,
    "skill_name" : "����ֱ��",
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�ѩӿ���ء���$w�����������⣬���¶��Ϸ���$n��$l",
    "force" : 140,
    "dodge" : 15,
    "damage" : 35,
    "lvl" : 19,
    "skill_name" : "ѩӿ����",
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С����ͻ�𡹣�����$w���ƺ�ɨʵ��б��������$n��$l",
    "force" : 160,
    "dodge" : 10,
    "damage" : 45,
    "lvl" : 29,
    "skill_name" : "���ͻ��",
    "damage_type" : "����"
]),
([  "action" : "$Nʹ����ҹ��̽������$w����������������಻�ϻ���$n��$l",
    "force" : 180,
    "dodge" : 10,
    "damage" : 60,
    "lvl" : 39,
    "skill_name" : "ҹ��̽��",
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�̩ɽѹ����������һ�󽣾�������$w���϶����������
��ֱ��$n��$l������ȥ",
    "force" : 210,
    "dodge" : 5,
    "damage" : 70,
    "lvl" : 49,
    "skill_name" : "̩ɽѹ��",
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�����滨�������ڰ�գ�$w�س飬���ֹ���$n��$l",
    "force" : 250,
    "dodge" : 10,
    "damage" : 90,
    "lvl" : 69,
    "skill_name" : "����滨",
    "damage_type" : "����"
]),
([  "action" : "$N��Ӱһ��, �Ƶ�$n����һ�С���¹��ԭ����������$n��$l����",
    "force" : 300,
    "dodge" : -5,
    "damage" : 100,
    "lvl" : 89,
    "skill_name" : "��¹��ԭ",
    "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
       return notify_fail("�������������\n");
    if ((int)me->query_skill("kurong-changong", 1) < 20)
       return notify_fail("��Ŀ����������̫ǳ��\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("duanjia-sword",1);
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
       return notify_fail("��������������μҽ���\n");
    me->receive_damage("qi", 20);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"duanjia-sword/" + action;
}

