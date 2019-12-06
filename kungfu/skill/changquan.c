//��ȭ changquan.c
//menpai skill(can also be used by non-menpai NPCs)

inherit SKILL;

mapping *action = ({
        ([      "action":
"ֻ��$N����һ�����������һ���������ڡ���׼$n�ı��Ӻ��������˹�ȥ",
                "dodge":                5,
                "parry":                5,
       "force":     90,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����һ�֣���ȭ������һ�С��β�Ѱ�ߡ�����$n��$l�к���ȥ",
                "dodge":                5,
                "parry":                5,
       "force":     60,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N��ȭ��$n����һ�Σ�����ʹ�˸���Ҷ��͵�ҡ���$n��$l����һץ",
                "dodge":                5,
                "parry":                5,
       "force":     60,
                "damage_type":  "ץ��"
        ]),
        ([      "action":
"$N����һ������ȭ��������ȭ���磬һ�С��ڻ����ġ��Ʋ��ɵ��ػ���$n$l",
                "dodge":                5,
                "parry":                5,
       "force":     80,
                "damage_type":  "����"
        ]),
        ([      "action":
"ֻ��$N������ʽ��һ�С�˫������ʹ�û����з硣����ȴ����һ������$n$l",
                "dodge":                5,
                "parry":                5,
       "force":     70,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N������𣬴��һ�����������С������ཻ����\n������$n���һ������ȭ����$n�������˹�ȥ",
                "dodge":                5,
                "parry":                5,
       "force":     120,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N�����󹭲���˫��ʹ�˸�������Ʊա���$n��$lһ��",
                "dodge":                5,
                "parry":                5,
       "force":     50,
                "damage_type":  "����"
        ]),
        ([      "action":
"ֻ��$N����������һ����ȭ����$n$l������һȭ�߹�һȭ��\n��һ�е����ֻ��൱���ţ�����������������",
                "dodge":                5,
                "parry":                5,
       "force":     80,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����һ�ݣ�����ʹ�˸��������̸���������ɨ��$n��$l",
                "dodge":                5,
                "parry":                5,
       "force":     50,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ��ת�����ƻ��أ����Ʒ���ʹ�˸���������ɽ����$n��ͷһ��",
                "dodge":                5,
                "parry":                5,
       "force":     90,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N����Ծ�𣬰����һ������$n���ţ�ȴ�Ǹ����С�\n˵ʱ����ʱ�죬ֻ��$Nһ��������˫���ѵ���$n��$l",
                "dodge":                5,
                "parry":                5,
       "force":     100,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon")
)
                return notify_fail("����ȭ������֡�\n");
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
   if( (int)me->query("jing") < 30)
     return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");
   if( (int)me->query("qi") < 30 )
     return notify_fail("����������������Ϣһ�������ɡ�\n");
   if( (int)me->query("neili") < 10 )
     return notify_fail("������������ˡ�\n");

   me->receive_damage("qi", 30);
   me->add("neili", -10);

   return 1;
}
