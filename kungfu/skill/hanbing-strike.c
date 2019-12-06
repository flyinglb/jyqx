// hanbing-strike.c   ���溮����
// by jacki(97.7.24)
// Modified by Venus Oct.1997

inherit SKILL;

mapping *action = ({
([  "action": "$N˫��һ��һ�С�������ӿ��������ɨ��$n��$l",
    "dodge": 30,
    "force": 200,
//      "poison": 80,
    "damage_type": "����"
]),
([  "action": "$Nһ�С���ѩ���졹������ͻȻ��ת��������$n��˫������$n��$l", 
    "dodge": 40,
    "force": 240,
//      "poison": 60,
    "damage_type": "����"
]),
([  "action": "$N�������������֣�һ�С�����ѩƮ����Ѹ���ޱȵ�ץ��$n��$l",   
    "dodge": 50,
    "force": 280,
//      "poison": 100,
    "damage_type": "����"
]),
([  "action": "$N����һ����ͻȻһ�С�ǧ����⡹����Ю�溮֮������$n��$l",   
    "dodge": 60,
    "force": 300,
//      "poison": 80
    "damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }   

mapping query_action(object me)
{
    if (random(me->query_skill("unarmed",1)) > 60 &&
   me->query_skill("force",1) > 50 &&
   me->query("neili") > 100 ) {
   me->add("neili", -100);
   return ([
   "action": "$N����ȫ��֮����һ�С����溮�����������ޱȵػ���$n",
   "force": 350,
   "damage_type": "����"]);
    }
    return action[random(sizeof(action))];
}

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("�����溮���Ʊ�����֡�\n");
    if ((int)me->query_skill("xuantian-force", 1) < 20)
   return notify_fail("�������������򲻹����޷������溮���ơ�\n")
;
    if ((int)me->query("max_neili") < 60)
   return notify_fail("�������̫�����޷���������");
    return 1;
}


int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
   return notify_fail("�������̫���ˣ�����Ϣһ�°ɡ�\n");
    if ((int)me->query("neili") < 8)
   return notify_fail("������������������ơ�\n");
    if (me->query_skill("hanbing-strike", 1) < 50)
   me->receive_damage("qi", 20);
    else
   me->receive_damage("qi", 30);
    me->add("neili", -5);
    return 1;
}

