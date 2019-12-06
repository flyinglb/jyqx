// seven-hurt.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N��������������Ƴ�ȭ��������$n��$l",
                "dodge":                20,
                "parry":                15,
                "force":                250,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫ȭһ��һ��������ɽ��������$n��$l���˹�ȥ",
                "dodge":                10,
                "parry":                 20,
                "force":                350,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���һ����һȭƽƽ�ػ���$n��$l",
                "dodge":                30,
                "parry":                10,
                "force":                150,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���ֻ��أ���ȭֱֱ�ػ���$n��$l",
                "dodge":                10,
                "parry":                30,
                "force":                260,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫��վ������������������������һȭ����$n$l",
                "dodge":                20,
                "parry":                30,
                "force":                400,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������$n��ǰ����һ�����У���ȭͻȻ����$n��$l",
                "dodge":                40,
                "parry":                10,
                "force":                200,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ������˫ȭ�����Ƴ�",
                "parry":                40,
                "force":                320,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("������ȭ������֡�\n");
        if( (int)me->query_skill("sunforce", 1) < 20 )
                return 
notify_fail("��ľ����񹦻���㣬�޷�������ȭ��\n");
        if( (int)me->query("max_force") < 150 )
                return notify_fail("�������̫�����޷�������ȭ����\n");
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        if( (int)me->query("force") < 5 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}

int enable_factor() { return 18; }

int learn_bonus() { return 12; }

int practice_bonus() { return 13; }

int study_bonus() { return 15; }