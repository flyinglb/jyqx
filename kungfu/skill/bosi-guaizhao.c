// bosi-guaizhao.c

inherit SKILL;

mapping *action = ({
        ([      "action": "$N���ƴ�����ĽǶ���$n��$lϮȥ��",
                "dodge":                -5,
                "parry":                20,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action": "$N����ת������Ȼ˫�ֻ���$n��$l��",
                "dodge":                30,
                "parry":                -10,
                "force":                200,
                "damage_type":  "����"
        ]),
        ([      "action": "$N�����мܣ�����ȴͻȻ���������ϵĽǶ���$n��ȥ��",
                "dodge":                -5,
                "parry":                10,
                "force":                150,
                "damage_type":  "����"
        ]),
        ([      "action": "$N�ڵ��Ϲ���������ȴͻȻ��б���д����ֱ����$n��$l��",
                "dodge":                10,
                "parry":                -5,
                "force":                210,
                "damage_type":  "����"
        ]),
        ([      "action": "$N���е�����˫�ֲ��ϵĴӱ������벻���ķ������$n��",
                "dodge":                -15,
                "parry":                -90,
                "force":                300,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����ʽ��ȫ�������ϣ����Ǽ���δ��������δ�ţ���ξ����ԴӲ����ܵķ���ͻϮ$n��",
                "parry":                -30,
                "force":                350,
                "damage_type":  "����"
        ]),
});
int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("����˹���б�����֡�\n");
        if( (int)me->query("max_neili") < 50 )
                return notify_fail("�������̫�����޷�����˹���С�\n");
        return 1;
}

int valid_enable(string usage) 
 { return usage=="unarmed" || usage=="parry"; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int practice_skill(object me)
{
        if (me->query_skill("unarmed", 1) <=me->query_skill("bosi-guaizhao", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
        if( (int)me->query("qi") < 10 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        if( (int)me->query("neili") < 10 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        me->receive_damage("qi", 10);
        me->add("neili", -10);
        return 1;
}

int practice_level()
{   
        return 200;
} 

