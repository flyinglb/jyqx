//liangyi-jian.c ���ǽ���

inherit SKILL;

mapping *action = ({
([      "name":   "��������",
        "action" : "$N���⽣â������һ�С��������ء�������$w�����´󿪴��أ�
һ��б�ϴ���$n��$l",
        "dodge" : 20,
        "damage" : 180,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "name":   "��������",
        "action" : "$N����Ȧת������$w��ճ������ƽƽչչ�ӳ���һ�С�������
�������Ữ��$n��$l",
        "dodge" : 20,
        "damage" : 160,
        "lvl" : 10,
        "damage_type" : "����"
]),
([      "name":   "Ԩ����ǳ",
        "action" : "$N��������������������������$wʹ��һʽ��Ԩ����ǳ������
$n��$l",
        "dodge" : 15,
        "damage" : 150,
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "name":   "ˮ�����",
        "action" : "$N������ָ��������ת��һ�С�ˮ����ơ�ֱȡ$n��$l",
        "dodge" : 15,
        "damage" : 200,
        "lvl" : 30,
        "damage_type" : "����"
]),
([      "name":   "�ƺ�����",
        "action" : "$N��â���£��������ߣ�����$wʹ��һʽ���ƺ����¡������Ƽ�
���������$n��$l",
        "dodge" : 25,
        "damage" : 180,
        "lvl" : 40,
        "damage_type" : "����"
]),
([      "name":   "���ѵ�ׯ",
        "action" : "$N�����ƽ���������ʵ��׷ɣ��ó�����ǹ⣬����$wʹ��һʽ
�����ѵ�ׯ��ԾԾ����Ʈ��$n��$l",
        "dodge" : 25,
        "damage" : 220,
        "lvl" : 50,
        "damage_type" : "����"
]),
([      "name":   "��������",
        "action" : "$N�ӽ��ֻ�����������ǰԾ��������$wһʽ���������ǡ�������
����֮�ƣ�����$n��$l",
        "dodge" : 15,
        "lvl" : 60,
        "damage" : 200,
        "damage_type" : "����"
]),
([      "name":   "��ϵ�̳�",
        "action" : "$N�˲������ֽ�ָ��ת������һŤ������$wһ�ǡ���ϵ�̳�������
���ϴ���$n��$l",
        "dodge" : 35,
        "damage" : 250,
        "lvl" : 80,
        "damage_type" : "����"
]),
});

int valid_enable(string usage){return (usage== "sword") || (usage== "parry");}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 200)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("taiji-shengong", 1) < 50)
                return notify_fail("���̫���񹦻��̫ǳ��\n");
        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("liangyi-jian", 1) )
                return notify_fail("��Ļ����������̫ǳ��\n");
        return 1;
}
mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("liangyi-jian",1);
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
                return notify_fail("����������������ǽ�����\n");
        me->receive_damage("qi", 10);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"liangyi-jian/" + action;
}

