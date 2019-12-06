// murong-jiafa Ľ�ݽ���

inherit SKILL;

mapping *action = ({
([      "action" : "$N������ָ��һʽ��ϴ����������˫�ź�������������ֱ��$n�Ȳ�",
        "force" : 120,
        "dodge" : 20,
        "damage" : 25,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N̤ǰ�����������ʵ������ʹһʽ�����������ֱ��$n������",
        "force" : 160,
        "dodge" : 15,
        "damage" : 30,
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�������������ⶶ����佣�����ֱ����$n���������Ҷ�",
        "force" : 220,
        "dodge" : 15,
        "damage" : 40,
        "lvl" : 45,
        "damage_type" : "����"
]),
([      "action" : "$N�����ڣ�����ָ��$n��������һ�С�����Ī��������������ǧ��һ�㣬��ɨ$n��$l",
        "force" : 270,
        "dodge" : 10,
        "damage" : 50,
        "lvl" : 60,
        "damage_type" : "����"
]),
([      "action" : "$N˫����أ�ʹ�����Ϸɣ�����ֱ��$n��һ�С��ﻢ���¡��������й���ƽ��$n��$l",
        "force" : 330,
        "dodge" : 10,
        "damage" : 60,
        "lvl" : 75,
        "damage_type" : "����"
]),
([      "action" : "$N��Цһ�����ὣб����һ�С���ש���񡹣��������$n��$l",
        "force" : 380,
        "dodge" : 5,
        "damage" : 70,
        "lvl" : 90,
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int valid_combine(string combo) { return combo=="murong-daofa"; }
int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 20)
                return notify_fail("�����Ԫ�����̫ǳ��\n");
        if ((int)me->query_skill("parry", 1) < 10)
                return notify_fail("��Ļ����мܻ��̫ǳ��\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
         level   = (int) me->query_skill("murong-jianfa",1);
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
        if ((int)me->query("jingli") < 50)
                return notify_fail("�������������Ľ�ݽ�����\n");
        me->receive_damage("jingli", 30);
        return 1;
}

