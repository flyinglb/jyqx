// duanyun-fu.c ���Ƹ�
// Modified by Venus Oct.1997

inherit SKILL;

mapping *action = ({
([  "action" : "$N����ڿ�Ծ��˫�ֽ���$w����׼$n��ͷ�������϶��µؿ�����ȥ��
ֻ�ڰ��������һ�ž޴�ĺ�Ӱ",
    "damage": 300,
    "dodge" : 50,
    "damage_type" : "����",
    "lvl" : 0,
    "skill_name" : "����ٵ�"
]),
([  "action" : "$NͻȻ��һ��������ǰ����������$w���¶��Ϸ���$n����·��$n����
һ������ɫ����Ӱ�����Լ�����֪�����æ�м�",
    "damage": 325,
    "dodge" : 45,
    "damage_type" : "����",
    "lvl" : 10,
    "skill_name" : "��������"
]),
([  "action" : "$N��Ȼ����һ��������б����ǰ�����һ��������΢�Σ�����$w�ڿ�
�л���һ����Ӱ�����ٺ�ɨ$n���Ҽ磬��������",
    "damage": 350,
    "dodge" : 40,
    "damage_type" : "����",
    "lvl" : 20,
    "skill_name" : "��ɨǧ��"
]),
([  "action" : "$NͻȻ�������ҹ������漴���𣬾��������һ˲�䣬�ѵ�������$w
����$n�����ߣ����ּȿ��Һ�",
    "damage": 390,
    "dodge" : 35,
    "damage_type" : "����",
    "lvl" : 30,
    "skill_name" : "����Ϊ��"
]),
([  "action" : "$N˫�ֺ��$w��ƽɨ$nǰ�أ���ʽδʹ�Ͼ��Ѵ�ס�Ȼ���У�����ֱ
ײ$n��С����",
    "damage": 430,
    "dodge" : 40,
    "damage_type" : "����",
    "lvl" : 42,
    "skill_name" : "��ײ��"
]),
([  "action" : "$N����������ת��΢�ף�$n��$N¶����������æ������ȴͻȻ����$N
��������ת����������$w��Ѹ�͵�ɨ���Լ�������",
    "damage": 480,
    "dodge" : 30,
    "parry" : 54,
    "damage_type" : "����",
    "lvl" : 55,
    "skill_name" : "�ط�ת��"
]),
([  "action" : "$N����΢��������ͬһʱ�������������ҿ����師��$n�����$w�Ӳ�
ͬ�ķ�λ�����Լ���һʱ�侹��֪������м�",
    "damage": 540,
    "dodge" : 25,
    "parry" : 66,
    "damage_type" : "����",
    "lvl" : 68,
    "skill_name" : "�師����"
]),
([  "action" : "$Nǰ���͵�������һ�٣����Ҳ΢΢һ�𣬽��ž���ͷ��ͷ����ת
��Ȧ��$w����������֮��ƽֱ�����ȵ�Ϯ��$n��$n������δ����㣬
�ܿ����������Լ�����һ�ߣ����ɴ�ʧɫ",
    "damage": 600,
    "parry" : 55,
    "dodge" : 65,
    "damage_type" : "����",
    "lvl" : 80,
    "skill_name" : "һ������"
])
});

int valid_enable(string usage) { return usage=="axe" ||  usage=="parry"; }      

int valid_learn(object me)
{
    if ((int)me->query_skill("force", 1) < 20)
   return notify_fail("����ڹ��ķ���򲻹����޷�ѧ���Ƹ���\n");
    if ((int)me->query("max_neili") < 150)
   return notify_fail("�������̫�����޷������Ƹ���\n");
    return 1;
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
    int i, level;
    level = (int)me->query_skill("duanyun-fu", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
    return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "axe")
   return notify_fail("��ʹ�õ��������ԡ�\n");    if ((int)me->
query("qi") < 30)
    if ((int)me->query("qi") < 50)
    return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
   return notify_fail("����������������Ƹ���\n");
    me->receive_damage("qi", 25);
return 1;
}
string perform_action_file(string action)
{
    return __DIR__"duanyun-fu/" + action;
}


