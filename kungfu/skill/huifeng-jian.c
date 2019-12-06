//huifeng-jian.c �ط������

inherit SKILL;

mapping *action = ({
([      "name":   "���Ϯ��",
        "action" : "$N���⽣â������һ�С����Ϯ�¡�������$w�����´󿪴��أ�
һ����������$n��$l",
        "force" : 120,
        "dodge" : 20,
        "damage" : 300,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "name":   "Ʈѩ����",
        "action" : "$N����Ȧת��һ�С�Ʈѩ���ơ�������$wƽչ�´̣�һ�����Ữ
��$n��$l",
        "force" : 120,
        "dodge" : 20,
        "damage" : 280,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "name":   "ǧ�徺��",
        "action" : "$N��������������������������$wʹ��һʽ��ǧ�徺�㡹����$n��
$l",
        "force" : 140,
        "dodge" : 15,
        "damage" : 350,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "name":   "��������",
        "action" : "$N������ָ��������ת��һ�С��������ڡ�ֱȡ$n��$l",
        "force" : 150,
        "dodge" : 15,
        "damage" : 280,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "name":   "��������",
        "action" : "$N��â���£��������ߣ�����$wʹ��һʽ���������������������
����$n��$l",
        "force" : 130,
        "dodge" : 25,
        "damage" : 300,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "name":   "������ɳ",
        "action" : "$N�����ƽ���������ʵ��׷ɣ��ó�����ǹ⣬����$wʹ��һʽ
��������ɳ��ԾԾ����Ʈ��$n��$l",
        "force" : 120,
        "dodge" : 25,
        "damage" : 320,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "name":   "��������",
        "action" : "$N�ӽ��ֻ�����������ǰԾ��������$wһʽ���������Ρ�������
����֮�ƣ�����$n��$l",
        "force" : 110,
        "dodge" : 15,
        "lvl" : 0,
        "damage" : 400,
        "damage_type" : "����"
]),
([      "name":   "��غ���",
        "action" : "$N�˲������ֽ�ָ��ת������һŤ������$wһ�ǡ���غ��衹����
���ϴ���$n��$l",
        "force" : 150,
        "dodge" : 35,
        "damage" : 400,
        "lvl" : 0,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 50)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 20)
                return notify_fail("����ټ�ʮ��ׯ���̫ǳ��\n");
//        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("huifeng-jian", 1))
//                return notify_fail("��Ļ����������̫ǳ��\n");
        return 1;
}
mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("huifeng-jian",1);
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
                return notify_fail("��������������ط��������\n");
        me->receive_damage("qi", 10);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"huifeng-jian/" + action;
}

