// juemen-gun.c ���Ź�
// Modified by Venus Oct.1997

inherit SKILL;

string *dodge_msg = ({
    "$n�ҽ�����һ��Ծ�������$N�Ĺ�����\n",
    "$n���Ա��˳���˳��һ��������һ�ߡ�\n",
    "$nб���ǰһ���������죬$N��һ���䵽�մ���\n",
    "$n��Ȼֱ������գ��ܾ�Ҳ������Ӱ�������������$N�ı���\n",
    "$nͻȻһ����ת��$N����һ�л�����һ�ߡ�\n",
});

mapping *action = ({
([  "action" : "$Nб���ǰһ���������죬����$w��ɨ$n��$l",
    "damage": 350,
    "dodge" : 50,
    "damage_type" : "����"
]),
([  "action" : "$N��Ȼֱ������գ��ܾ�Ҳ������Ӱ��$n����Ѱ�䣬$N��
�������£�$w����$n��$l",
    "damage": 400,
    "dodge" : 45,
    "damage_type" : "����"
]),
([  "action" : "$Nԭ��һ���������ȴ����ص�һɲ�ǣ�������$nƽ�ɹ�
ȥ������$wָ��$n��$l",
    "damage": 350,
    "dodge" : 60,
    "damage_type" : "����"
]),
([  "action" : "$NͻȻһ����ת��$w��ɨһȦ��Ю�����ҵľ�������$n��$l",    
    "damage": 450,
    "dodge" : 75,
    "damage_type" : "����"
]),
([  "action" : "$N��ǰ�˳���˳��һ�������ŷ�����������$wб���ϻ�
��$n��$l",
    "damage": 400,
    "dodge" : 65,
    "damage_type" : "����"
])
});

int valid_enable(string usage){return usage=="staff" || usage=="parry"|| usage==
"dodge"; }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
   return notify_fail("�������̫�����޷������Ź���\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
   return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
   return notify_fail("����������������Ź���\n");
    me->receive_damage("qi", 20);
    return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

