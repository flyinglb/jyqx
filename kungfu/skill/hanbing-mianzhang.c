// hannbing-mianzhang.c ��������
// pal 1997.05.26
inherit SKILL;
mapping *action = ({
([  "action" : "$Nһʽ��"+RED+"�󽭶�ȥ"+NOR+"����˫�ƴ󿪴�ϣ�ֱ��$n��$l��ȥ",
    "force" : 180,
    "lvl" : 0,
    "skill_name" : RED "�󽭶�ȥ" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N����һ�䣬һʽ��"+YEL+"�ƺӾ���"+NOR+"����˫��������ֱ������$n��$l",
    "force" : 220,
    "lvl" : 10,
    "skill_name" : YEL "�ƺӾ���" NOR, 
        "damage_type" : "����"
]),
([  "action" : "$Nʹһʽ��"+BLU+"����ɽɫ"+NOR+"����������΢����棬������ϸ�����ֱȡ$n��$l",
    "force" : 260,
    "lvl" : 20,
    "skill_name" : BLU "����ɽɫ" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N����һ�֣�һʽ��"+MAG+"�����׺�"+NOR+"��������������������$n�����ȥ",
    "force" : 300,
    "lvl" : 30,
    "skill_name" : MAG "�����׺�" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N����һת��ʹ��һʽ��"+BLU+"ˮ������"+NOR+"����ֻ��������Ӱ��ס��$n��ȫ��",
    "force" : 340,
    "lvl" : 40,
    "skill_name" : BLU "ˮ������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$NͻȻ����һ����ʹ��һʽ��"+RED+"С�����"+NOR+"�����������أ�������ӯ������$n��$l",
    "force" : 380,
    "lvl" : 50,
    "skill_name" : RED "С�����" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nʹһʽ��"+HIW+"��ѩ��ɽ"+NOR+"����˫��Ю��籩ѩ֮�ƣ��͵�����$n��$l",
    "force" : 420,
    "lvl" : 60,
    "skill_name" : HIW "��ѩ��ɽ" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+HIW+"˪������"+NOR+"����˫�ƴ�����ɪ������������$n��$l",
    "force" : 460,
    "lvl" : 70,
    "skill_name" : RED "˪������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N����Ȼһ�䣬ʹ��һʽ��"+YEL+"�������"+NOR+"������Ӱǧ����ã���$n�޷�����",
    "force" : 500,
    "lvl" : 80,
    "skill_name" : YEL "�������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N��Хһ����һʽ��"+MAG+"��˪ѩ��"+NOR+"����˫�ƻ��裬��ͬѩ������ת������$n��$l",
    "force" : 540,
    "lvl" : 90,
    "skill_name" : MAG "��˪ѩ��" NOR,
        "damage_type" : "����"
])
});
int practice_level(){   return 90;  }
int valid_enable(string usage)
{
    return usage=="unarmed" || usage=="parry" ;
}
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("���������Ʊ�����֡�\n");
//    if ((int)me->query_skill("huagong-dafa", 1) < 20)
//        return notify_fail("��Ļ����󷨻�򲻹����޷�ѧ�������ơ�\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷����������ơ�\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("hanbing-mianzhang", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
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
    mapping a_action;
    level   = (int) me->query_skill("hanbing-mianzhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
/*
    a_action["dodge"]  = 0-level/2;
    a_action["parry"]  = 0-random(level/2);
    a_action["damage"] = level;
*/
    return a_action;
}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("���������Ʊ�����֡�\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 40)
        return notify_fail("��������������������ơ�\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
if( random(me->query_skill("hanbing-mianzhang")) > 10 )
    victim->apply_condition("ice_poison", random(me->query_skill("hanbing-mianzhang",1)/10) + 1 + victim->query_condition("ice_poison"));
}
string perform_action_file(string action)
{
    return __DIR__"hanbing-mianzhang/" + action;
}

