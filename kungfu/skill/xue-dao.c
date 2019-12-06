//
// xue-dao.c Ѫ��
// Designed by secret(����)
//
inherit SKILL;
mapping *action = ({
([      "action" : "$N�߾�����$w,ʹ��һ�С�"+RED+"ĥ��˱Ѫ"+NOR+"����һ��б��$n��$l  ",
        "skill_name" : RED "ĥ��˱Ѫ" NOR,
        "force" : 100,
        "dodge" : 5,
        "parry" : -5,
        "lvl" : 0,
        "damage" : 20,
        "damage_type" : "����",
]),
([      "action" : "$N�͵�һ����ʹһ�С�"+RED+"��Ѫ����"+NOR+"��������$w����$n�Ĵ���  ",
        "skill_name" : RED "��Ѫ����" NOR,
        "force" : 140,
        "dodge" : 5,
        "parry" : -5,
        "lvl" : 8,
        "damage" : 25,
        "damage_type" : "����",
]),
([      "action" : "$N���һ�㣬ʹ����"+RED+"Ѫ��ãã"+NOR+"�����������϶���ֱ��$n��$l  ",
        "skill_name" : RED "Ѫ��ãã" NOR,
        "force" : 180,
        "dodge" : 10,
        "parry" : -5,
        "lvl" : 16,
        "damage" : 30,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�"+RED+"Ż����Ѫ"+NOR+"������$w��������һ��ѹ��$n  ",
        "skill_name" : RED "Ż����Ѫ" NOR,
        "force" : 220,
        "dodge" : 5,
        "parry" : -5,
        "lvl" : 24,
        "damage" : 40,
        "damage_type" : "����",
]),
([      "action" : "$N�ͺ�һ����ʹ����"+RED+"Ѫ������"+NOR+"������$wֱ��$n��$l  ",
        "skill_name" : RED "Ѫ������" NOR,
        "force" : 250,
        "dodge" : 5,
        "parry" : -5,
        "lvl" : 32,
        "damage" : 50,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ����"+RED+"Ѫ���߰�"+NOR+"��������б�̣���Ȼ����һ����ն$n������  ",
        "skill_name" : RED "Ѫ���߰�" NOR,
        "force" : 280,
        "dodge" : 10,
        "parry" : -5,
        "lvl" : 40,
        "damage" : 60,
        "damage_type" : "����",
]),
([      "action" : "$Nʹһʽ��"+RED+"��Ѫ��Ѫ"+NOR+"�����ӵ�ֱָ$n���ؿ�  ",
        "skill_name" : RED "��Ѫ��Ѫ" NOR,
        "force" : 300,
        "dodge" : 5,
        "parry" : -10,
        "lvl" : 48,
        "damage" : 80,
        "damage_type" : "����",
]),
([      "action" : "$N������㣬ʹ��һ�С�"+RED+"Ѫ������"+NOR+"����ת���$w����$n������  ",
        "skill_name" : RED "Ѫ������" NOR,
        "force" : 320,
        "dodge" : 10,
        "parry" : -20,
        "lvl" : 56,
        "damage" : 100,
        "damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int practice_level(){   return 56;  }
//int valid_combine(string combo) { return combo=="mingwang-jian"; }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 50)
        return notify_fail("�������������\n");
    if (me->query_skill("blade", 1) <=me->query_skill("xue-dao", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    if ((int)me->query_skill("longxiang", 1) >= 20 ||
        (int)me->query_skill("xiaowuxiang", 1) >= 20)
        return 1;
    else if ((int)me->query_skill("longxiang", 1) < 20)
        return notify_fail("���������������̫ǳ��\n");
    else if ((int)me->query_skill("xiaowuxiang", 1) < 20)
        return notify_fail("���С���๦���̫ǳ��\n");
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
    level   = (int) me->query_skill("xue-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("�������������������Ѫ����\n");
    me->receive_damage("qi", 30);
    return 1;
 }
string perform_action_file(string action)
{
    return __DIR__"xue-dao/" + action;
}

