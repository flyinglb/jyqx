// jinshe-zhang.c
inherit SKILL;
mapping *action = ({
        ([      "name" :  "ǧ�߳���",
                "action": "$N˫��һ��һ�С�ǧ�߳������ó�������Ӱ£��$n��$l",
                "dodge":  30,
                "parry":  10,
                "damage": 50,
                "damage_type":  "����"
        ]),
        ([      "name" :  "ħ�����",
                "action": "$N����һ����˫�������Ƴ���һ�С��������ߡ�ǿ�����Ʒ�ֱ��$n��$l",
                "dodge":  30,
                "parry":  10,
                "damage": 50,
                "damage_type":  "����"
        ]),
        ([      "name" :  "˫������",
                "action": "$N˫�Ʒ׷ɣ�һ�С�˫�����项ֱȡ$n��$l",
                "dodge":  10,
                "parry":  30,
                "damage": 30,
                "damage_type":  "����"
        ]),
        ([      "name" :  "����ʽ",
                "action": "$N�����������ߣ�һ�С�����ʽ����ɭɭ�Ʒ��޿ײ����ػ���$n��$l",
                "dodge":  10,
                "parry":  50,
                "damage": 70,
                "damage_type":  "����"
        ]),
        ([      "name" :  "����ʽ",
                "action": "$N�������˫��ƽ�ƣ����������һ�С�����ʽ������$n��$l",
                "dodge":  30,
                "parry":  70,
                "damage": 30,
                "damage_type":  "����"
        ]),
        ([      "name" :  "��������",
                "action": "$N����������ǰ�������Ƴ���һ�С��������ơ�����$n$l",
                "dodge":  30,
                "parry":  70,
                "damage": 30,
                "damage_type":  "����"
        ]),
        ([      "name" :  "���߷���ҧ",
                "action": "$Nʹ�������߷���ҧ����������շ��𣬴ӿ��е�ͷ��$n��$l���ƹ���",
                "dodge":  30,
                "parry":  70,
                "damage": 30,
                "damage_type":  "����"
        ]),
        ([      "name" :  "������Ӱ",
                "action": "$Nʹ��һ�С�������Ӱ�������ƻ���Ϊʵ����$n��$l",
                "dodge":  30,
                "parry":  70,
                "damage": 30,
                "damage_type":  "����"
        ]),
        ([      "name" :  "���߲�˿��",
                "action": "$N���ƻ��˸�ȦȦ�������Ƴ���һ�С����߲�˿�֡�����$n$l",
                "dodge":  30,
                "parry":  70,
                "damage": 30,
                "damage_type":  "����"
        ]),
        ([      "name" :  "�����ΰ˷�",
                "action": "$Nʹ���������ΰ˷���������ɢ���˴�ͬʱ��$n��$l���ƹ���",
                "dodge":  30,
                "parry":  70,
                "damage": 30,
                "damage_type":  "����"
        ]),
        ([      "name" :  "����̽ͷ",
                "action": "$Nʹ�����������Ʒ�������̽ͷ��������Ȱ�����$n��ǰ��һ������$n��$l",
                "dodge":  30,
                "parry":  70,
                "damage": 30,
                "damage_type":  "����"
        ]),
        ([      "name" :  "��������",
                "action": "$N�������ᣬȫ�����һ�С��������졹��˫��������£�$n��ȫ��������������֮��",
                "dodge":  30,
                "parry":  70,
                "damage": 30,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
	if( (int)me->query_skill("jinshe-zhang",1) < 200 )
		return notify_fail("����������Ҫ200�����ϲ���������\n");
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("�����������Ʊ�����֡�\n");
        if( (int)me->query("max_neili", 1) < 500)
                return notify_fail("����������㣬�޷������������ơ�\n");
//	return notify_fail("����������û�����ڡ�\n");
	return 1;
}

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 30 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        if( (int)me->query("neili") < 5 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        me->receive_damage("qi", 30);
        me->add("force", -5);
        return 1;
}
int effective_level() { return 10;}
 
string *parry_msg = ({
        "$nʹ����ճ���־���˫��һ������ƫ��$N��$w��\n",
});

string *unarmed_parry_msg = ({
        "$nʩչ�����������ƣ����赭д�Ļ�����$N�Ĺ��ơ�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string perform_action_file(string action)
{
        return __DIR__"jinshe-zhang/" + action;
}

