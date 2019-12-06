// quanzhen-jian.c ȫ�潣��

inherit SKILL;

mapping *action = ({
([      "action":"$Nʹһʽ��̽��������������$w�������Һ�ɨ����$n��$l",
        "force" : 120,
        "dodge" : 0,
        "damage": 30,
        "lvl" : 0,
        "skill_name" : "̽������",
        "damage_type":  "����"
]),
([      "action":"$N̤��һ�������ɨҶ��������$w���������һ����������$n��$l",
        "force" : 140,
            "dodge" : 10,
        "damage": 40,
        "lvl" : 9,
        "skill_name" : "�ɨҶ",
        "damage_type":  "����"
]),
([      "action":"$N����$wһ����һ�С�˳ˮ���ۡ���ббһ�������ó�������$n��$l",
        "force" : 160,
           "dodge" : 5,
        "damage": 50,
        "lvl" : 18,
        "skill_name" : "˳ˮ����",
        "damage_type":  "����"
]),
([      "action":"$N����$w����������Ȧ��һʽ���ǳڵ�������һ���������$n��$l",
        "force" : 180,
        "dodge" : 10,
        "damage": 65,
        "lvl" : 27,
        "skill_name" : "�ǳڵ���",
        "damage_type":  "����"
]),
([      "action":"$Nһʽ���׺����᡹��������չ������$w����$n��$l",
        "force" : 220,
        "dodge" : 15,
        "damage": 80,
        "lvl" : 36,
        "skill_name" : "�׺�����",
        "damage_type":  "����"
]),
([      "action":"$N����$wбָ���죬һʽ������Į��������׼$n��$lбб����",
        "force" : 260,
        "dodge" : 5,
        "damage": 100,
        "lvl" : 44,
        "skill_name" : "����Į��",
        "damage_type":  "����"
]),
([      "action":"$Nһʽ�������仨�������󼱶�������������⣬����$n��$l",
        "force" : 320,
        "dodge" : 5,
        "damage": 105,
        "lvl" : 52,
        "skill_name" : "�����仨",
        "damage_type":  "����"
]),
([      "action":"$Nһʽ����Ʒ��̨����$w��ն�������缲�������$n���ؿ�",
        "force" : 380,
        "dodge" : 5,
        "damage": 125,
        "lvl" : 60,
        "skill_name" : "��Ʒ��̨",
        "damage_type":  "����"
]),
([      "action":"$Nʹһʽ��������ء�������$w������$n���ؿڣ������ɵ�",
        "force" : 380,
        "dodge" : 5,
        "damage": 125,
        "lvl" : 70,
        "skill_name" : "�������",
        "damage_type":  "����"
]),
([      "action":"$N����$w����һ�������Ļ��ߣ�����$n��$l��ȴ��һ�С���ʷ������",
        "force" : 380,
        "dodge" : 5,
        "damage": 140,
        "lvl" : 80,
        "skill_name" : "��ʷ����",
        "damage_type":  "����"
]),
([      "action":"$N�ؽ����أ�ʹһʽ��������项���������$w��$n����",
        "force" : 380,
        "dodge" : 5,
        "damage": 140,
        "lvl" : 90,
        "skill_name" : "�������",
        "damage_type":  "����"
]),
([      "action":"$N��������һʽ�������߶�����$w�Ӳ���˼��ĽǶȴ���$n",
        "force" : 380,
        "dodge" : 5,
        "damage": 140,
        "lvl" : 114,
        "skill_name" : "�����߶�",
        "damage_type":  "����"
]),
([      "action":"$Nһʽ���ϵ紩�ơ���$wͻȻ���������һƬ���Χ��$nȫ��",
        "force" : 380,
        "dodge" : 5,
        "damage": 155,
        "lvl" : 129,
        "skill_name" : "�ϵ紩��",
        "damage_type":  "����"
])
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
        if ((int)me->query_skill("yunv-xinfa", 1) < 15 &&
            (int)me->query_skill("xiantian-qigong", 1) < 15)
                return notify_fail("����ڹ��ķ���򲻵����޷�ѧϰȫ�潣����\n");
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
        level   = (int) me->query_skill("quanzhen-jian",1);
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
                return notify_fail("�������������ȫ�潣����\n");
        me->receive_damage("qi", 25);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"quanzhen-jian/" + action;
}
