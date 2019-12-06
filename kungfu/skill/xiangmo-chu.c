//
// xiangmo-chu.c ��ս�ħ��
//
inherit SKILL;
mapping *action = ({
([      "action" : "$N�߾�����$w��ʹ��һ�С�"+BLK+"�������"+NOR+"����ֱ��$n��$l  ",
        "skill_name" : BLK "�������" NOR,
        "lvl" : 0,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ����"+YEL+"��շ�ħ"+NOR+"���������趯$w��һ����$w��ɨ$n������  ",
        "skill_name" : YEL "��շ�ħ" NOR,
        "lvl" : 8,
        "damage_type" : "����",
]),
([      "action" : "$N�������棬ʹ��һʽ��"+YEL+"�������"+NOR+"����˫����$W��һ��ֱ��$n��$l  ",
        "skill_name" : YEL "�������" NOR,
        "lvl" : 16,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�"+MAG+"��Ȥ����"+NOR+"����˫�־ٹ�����$n���ɲ�  ",
        "skill_name" : MAG "��Ȥ����" NOR,
        "lvl" : 24,
        "damage_type" : "����",
]),
([      "action" : "$N�趯����$w��ʹ����"+HIR+"��������"+NOR+"������ʱ��ס$n��ȫ��  ",
        "skill_name" : HIR "��������" NOR,
        "lvl" : 32,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�"+RED+"����Ѫ��"+NOR+"����ȫ�����ض��ɣ�һ��ֱ��$n��$l  ",
        "skill_name" : RED "����Ѫ��" NOR,
        "lvl" : 40,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һʽ��"+HIY+"������ħ"+NOR+"�����Թ�֧�أ�˫��ɴ�$n������  ",
        "skill_name" : HIY "������ħ" NOR,
        "lvl" : 48,
        "damage_type" : "����",
]),
([      "action" : "$N�������ƣ�ʹ����"+HIB+"��ħ����"+NOR+"����������������$w��ɨ$n��$l  ",
        "skill_name" : HIB "��ħ����" NOR,
        "lvl" : 56,
        "damage_type" : "����",
]),
});
int valid_enable(string usage) { return usage == "staff" || usage == "parry"; }
int practice_level(){   return 56;  }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "staff")
        return notify_fail("��ʹ�õ��������ԡ�\n");

    if ((int)me->query("max_neili") < 50)
        return notify_fail("�������������\n");
    if (me->query_skill("staff", 1) <=me->query_skill("xiangmo-chu", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    if ((int)me->query_skill("longxiang", 1) < 20)
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
        mapping a_action;
        int i, level;
        level   = (int) me->query_skill("xiangmo-chu",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-level;
    a_action["attack"]  = level/2;
    a_action["damage"] = level;
    return a_action;
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "staff")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("������������������˽�ս�ħ�ơ�\n");
    me->receive_damage("qi", 30);
    return 1;
}
