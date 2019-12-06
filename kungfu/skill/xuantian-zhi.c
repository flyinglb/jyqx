// xuantian-zhi.c
inherit SKILL;

mapping *action = ({
([      "action" : "$N��ָ�ӳ���һʽ����Ȼ���꡹������$n����Ե",
        "force" : 100,
        "dodge" : 5,
        "lvl" : 0,
        "skill_name" : "��Ȼ����",
        "damage_type" : "����"
]),
([      "action" : "$Nȫ��֮������һָ��һʽ���������项��ָ��$n����ǰ",
        "force" : 140,
        "dodge" : 5,
        "lvl" : 15,
        "damage" : 25,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N�����������Ѩ������һʽ��������֡�����$n��$l����",
        "force" : 180,
        "dodge" : 8,
        "lvl" : 25,
        "damage" : 55,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$N˫Ŀŭ�ӣ�һʽ���������ġ���˫ָ����$n�Ķ�����硢�ۡ���
����",
        "force" : 220,
        "dodge" : 5,
        "damage": 65,
        "lvl" : 45,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ���������ˡ��������������⣬��ָ���Ƶ���$n��$l",
        "force" : 260,
        "dodge" : 15,
        "damage": 80,
        "lvl" : 60,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N���������ʮָ�濪��һʽ�����߱��项��Сָ����$n��̫ԨѨ",
        "force" : 330,
        "dodge" : 20,
        "damage": 100,
        "lvl" : 70,
        "skill_name" : "���߱���",
        "damage_type" : "����"
]),
([      "action" : "$N˫�ų�������������һʽ���������ࡹ����$n��ȫ��",
        "force" : 400,
        "dodge" : 25,
        "damage": 120,
        "lvl" : 80,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }


int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����������ָ������֡�\n");
//        if ((int)me->query_skill("wuzheng-xinfa", 1) < 80)
//                return notify_fail("��������ķ���򲻹����޷�ѧ��������ָ��\n");
        if ((int)me->query("max_neili") < 300)
                return notify_fail("�������̫�����޷�����������ָ��\n");
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
        level   = (int) me->query_skill("xuantian-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jing") < 30)
                return notify_fail("��ľ�̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("���������������������ָ��\n");
        me->receive_damage("jing", 30);
        me->add("neili", -10);
        return 1;
}

