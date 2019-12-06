//
// yujiamu-quan.c ������ĸȭ
//
inherit SKILL;
mapping *action = ({
([      "action" : "$N����˫ȭ��ʹ��һ�С�"+RED+"�ඥ"+NOR+"������ͷ����$n��$l  ",
        "skill_name" : RED "�ඥ" NOR,
        "lvl" : 0,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�"+BLU+"���"+NOR+"��������һ�ͣ����ֻ���������һȭ����$n���ɲ�  ",
        "skill_name" : BLU "���" NOR,
        "lvl" : 8,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�"+YEL+"�ü"+NOR+"������ȭ���$n��ǰ�أ�һ������ȭ��ɨ$n��̫��Ѩ  ",
        "skill_name" : YEL "�ü" NOR,
        "lvl" : 16,
        "damage_type" : "����",
]),
([      "action" : "$N���ι��죬ʹһ�С�"+HIR+"���"+NOR+"����˫ȭ���»���$n��$l  ",
        "skill_name" : HIR "���" NOR,
        "lvl" : 24,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�"+HIC+"����"+NOR+"����˫ȭ������������������ֱָ$n��$l  ",
        "skill_name" : HIC "����" NOR,
        "lvl" : 32,
        "damage_type" : "����",
]),
([      "action" : "$N΢΢һЦ��ʹ��һʽ��"+GRN+"����"+NOR+"����˫ȭǰ�������ֱȡ$n������  ",
        "skill_name" : GRN "����" NOR,
        "lvl" : 40,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�"+HIW+"����"+NOR+"����ȫ��ת��˫ȭ��ɨ$n��$l  ",
        "skill_name" : HIW "����" NOR,
        "lvl" : 48,
        "damage_type" : "����",
]),
([      "action" : "$N����һԾ��ʹ��һ�С�"+MAG+"��ʤ"+NOR+"����һȭ�ͻ�$n�ʺ�  ",
        "skill_name" : MAG "��ʤ" NOR,
        "lvl" : 56,
        "damage_type" : "����",
]),
});
int valid_enable(string usage) { return usage == "unarmed" || usage == "parry"; }
int practice_level(){   return 56;  }

int valid_combine(string combo) { return combo=="dashou-yin"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("��������ĸȭ������֡�\n");
    else if ((int)me->query("max_neili") < 50)
        return notify_fail("�������������\n");
    else if ((int)me->query_skill("longxiang", 1) < 20)
        return notify_fail("���������������̫ǳ��\n");
    else if ((int)me->query_skill("xiaowuxiang", 1) < 20)
        return notify_fail("���С���๦���̫ǳ��\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("yujiamu-quan", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
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
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("yujiamu-quan",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level/2;
    a_action["parry"]  = 0-level/2;
    a_action["damage"] = level/2;
    return a_action;
}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("��������ĸȭ������֡�\n");
    if ((int)me->query("qi") < 40)
        return notify_fail("������������������˽�����ĸȭ��\n");
    me->receive_damage("qi", 20);
    return 1;
}
