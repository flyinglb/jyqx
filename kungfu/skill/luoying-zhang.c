// luoying.c
inherit SKILL;
mapping *action = ({
    ([  "action":       "$Nʹһ�С�"+RED+"��Ӣ�ͷ�"+NOR+"����˫��Ʈ�Ʋ�������$n$l",
        "dodge": 30,
        "parry": 20,
        "force": 120,
        "damage_type": "����"
    ]),
    ([  "action":       "$Nٿ������$n��ǰ��һ�С�"+MAG+"�����һ�"+NOR+"��ֱ��$n��$l",
        "dodge": -20,
        "parry": -20,
        "force": 160,
        "damage_type": "����"
    ]),
 ([  "action":"$N������$nһת��һ�С�"+HIY+"��������"+NOR+"����$n$l��������",
        "dodge":  25,
        "parry":  20,
        "force": 200,
        "damage_type": "����"
    ]),
    ([  "action":       "$N���ΰ����ڰ��һ�С�"+HIC+"���Ƿɻ�"+NOR+"�������ͻ�$n��$l",
        "dodge": -30,
        "parry": -30,
        "force": 240,
        "damage_type": "����"
    ]),
    ([  "action":       "$Nʹһ�С�"+HIM+"������"+NOR+"������������ֱ��$n��$l",
        "dodge": -20,
        "parry":  40,
        "force": 280,
        "damage_type": "����"
    ]),
    ([  "action":       "$Nһ�����ʹ����"+HIM+"���컨��"+NOR+"�����ó�������Ӱ�����Ʋ���$n��$l",
        "dodge":  40,
        "force": 340,
        "damage_type": "����"
    ]),
});
  int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }
int practice_level(){   return 60;  }
int valid_combine(string combo) { return combo=="xuanfeng-leg"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("����Ӣ���Ʊ�����֡�\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷�����Ӣ���ơ�\n");
    if (me->query_skill("strike", 1) <=me->query_skill("luoying-zhang", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}
int practice_skill(object me)
{
    if ((int)me->query("qi") < 40)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 10)
        return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
    me->receive_damage("qi", 30);
    me->add("neili", -5);
    return 1;
}
