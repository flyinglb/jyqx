//
// hujia-daofa.c 
// Designed by secret(����)
//
inherit SKILL;
mapping *action = ({
([      "action" : "$N����$w���ƣ�һ�С�"+BLU+"�Ʋ�����"+NOR+"��������������$nl��ȥ  ",
        "skill_name" : BLU "�Ʋ�����" NOR,
        "force" : 80,
        "dodge" : -10,
        "parry" : 10,
        "lvl" : 0,
        "damage" : 25,
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С�"+RED+"ɳŸ�Ӳ�"+NOR+"�����������¶��ϻ��˸��뻡��$wһ��һ�գ�ƽ�л���$n�ľ���  ",
        "skill_name" : RED "ɳŸ�Ӳ�" NOR,
        "force" : 100,
        "dodge" : 5,
        "parry" : 10,
        "lvl" : 8,
        "damage" : 30,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�"+BLU+"��������"+NOR+"������$w��������һ��ѹ��$n ",
        "skill_name" : BLU "��������" NOR,
        "force" : 120,
        "dodge" : 10,
        "parry" : 10,
        "lvl" : 16,
        "damage" : 35,
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С�"+YEL+"��������"+NOR+"����$w������б����$n��ȥ ",
        "skill_name" : "��������",
        "force" : 150,
        "dodge" : 5,
        "parry" : 10,
        "lvl" : 24,
        "damage" : 40,
        "damage_type" : "����",
]),
([      "action" : "$N����$w��ת��Ծ��һ�С�"+MAG+"��´���"+NOR+"����һ���׹�����$n���ؿ� ",
        "skill_name" : MAG "��´���" NOR,
        "force" : 200,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 32,
        "damage" : 45,
        "damage_type" : "����",
]),
([      "action" : "$N����$w��ʹ��һ�С�"+HIW+"�׺����"+NOR+"�����������ã����ҿ�����������$n  ",
        "skill_name" : HIW "�׺����" NOR,
        "force" : 230,
        "dodge" : 10,
        "parry" : 5,
        "lvl" : 40,
        "damage" : 50,
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С�"+RED+"������ů"+NOR+"�������Ծ����أ�$w˳����ǰ��Ю��������$n��$l  ",
        "skill_name" : RED "������ů" NOR,
        "force" : 300,
        "dodge" : 5,
        "parry" : 10,
        "lvl" : 48,
        "damage" : 60,
        "damage_type" : "����",
]),
([      "action" : "$N ����ʹһ�С�"+MAG+"�˷��ص�"+NOR+"������ʱ�����������䵶��������˷�ӿ��$nȫ��  ",
        "skill_name" : MAG "�˷��ص�" NOR,
        "force" : 320,
        "dodge" : 10,
        "parry" : 20,
        "lvl" : 56,
        "damage" : 70,
        "damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
//int valid_combine(string combo) { return combo=="mingwang-jian"; }
int practice_level(){   return 56;  }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 1200)
        return notify_fail("�������������\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) >= 20 ||
        (int)me->query_skill("force", 1) >= 20)
        return 1;
    else if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
        return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");
    else if ((int)me->query_skill("force", 1) < 20)
        return notify_fail("��Ļ����ڹ����̫ǳ��\n");
    if (me->query_skill("blade", 1) <=me->query_skill("hujian-daofa", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
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
    level   = (int) me->query_skill("hujia-daofa",1);
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
        return notify_fail("������������������˺��ҵ�����\n");
    me->receive_damage("qi", 30);
    return 1;
}
