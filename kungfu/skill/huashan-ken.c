// huashan-ken.c ��ɽȭ��
// Modified by Venus Oct.1997

inherit SKILL;

mapping *action = ({
    ([  "action":      "$Nʹһ�С�����Ǭ������ȭ������������ʽʹ�ϣ���ȭ�Ѵ���ȭ֮�״�������׼$n��$l��������һȭ",
   "dodge":   -40,
   "parry":   40,
   "damage_type":  "����"
    ]),
    ([  "action":      "$N��ȭͻȻ�ſ���ȭ�����ƣ�ֱ����Ϊ��ɨ��һ�С����￴��������$n��$l�к���ȥ",
   "dodge":   -30,
   "parry":   30,
   "damage_type":  "����"
    ]),
    ([  "action":      "$N���ֻ�����ԣ�����һȦ��һ�С������������$n��$l����",
   "dodge":   -30,
   "parry":   30,
   "damage_type":  "����"
    ]),
    ([  "action":      "$N����һ������ȭ���һ�У���ȭʹ����÷��ŪӰ������$n$l",
   "dodge":   -30,
   "parry":   30,
   "damage_type":  "����"
    ]),
});

int valid_learn(object me)
{
    if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
   return notify_fail("����ɽȭ��������֡�\n");
    return 1;
}

int valid_enable(string usage)
{
    return usage=="unarmed" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    if( (int)me->query("qi") < 30 )
   return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
    me->receive_damage("qi", 30);
    return 1;
}

