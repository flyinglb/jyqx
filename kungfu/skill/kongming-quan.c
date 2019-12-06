// kongming.c
inherit SKILL;
mapping *action = ({
    ([  "action":       "$Nʹһ�С�"+HIB+"����ס��"+NOR+"����˫����ƮƮ�ع���$n$l",
        "force": 80,
        "damage_type": "����"
    ]),
    ([  "action":       "$N����һƽ,����һ��,һ�С�"+HIB+"����ʢ��"+NOR+"��ֱ��$n��$l",
        "force": 120,
        "damage_type": "����"
    ]),
    ([  "action":       "$N������$nһת��˫������,һ�С�"+HIB+"�ղ�װˮ"+NOR+"������$n$l",
        "force": 160,
        "damage_type": "����"
    ]),
    ([  "action":       "$N����һ��,����һ��,һ�С�"+HIB+"�黳����"+NOR+"������$n��$l",
        "force": 200,
        "damage_type": "����"
    ]),
    ([  "action":       "$Nʹһ�С�"+HIB+"��ɽ����"+NOR+"����$n��$l��Χ��$N��������Ӱ֮��",
        "force": 240,
        "damage_type": "����"
    ]),
    ([  "action":       "$N��ɫһ����ʹ����"+HIB+"���Ŀ���"+NOR+"����Χ��$n��$l��������",
        "force": 300,
        "damage_type": "����"
    ]),
});
int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("������ȭ������֡�\n");
    if ((int)me->query("max_neili") < 150)
        return notify_fail("�������̫�����޷�������ȭ��\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("kongming-quan", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int level   = (int) me->query_skill("kongming-quan",1);
    a_action = action[random(sizeof(action))];
    a_action["dodge"]  = 0-level;
    a_action["attack"]  = 2*level;
    a_action["damage"] = level;
    return a_action;

}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("������ȭ������֡�\n");
    if ((int)me->query("qi") < 40)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 10)
        return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
    me->receive_damage("qi", 30);
    me->add("neili", -5);
    return 1;
}
