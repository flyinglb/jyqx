// tiangang-zhi.c ���ָѨ��
// modified by Venus Oct.1997
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N�������Ღ����������ָ���쵯������һʽ��������ġ���      
����$n��$l",
    "force" : 150,
    "dodge" : 5,
    "damage_type" : "����",
    "lvl" : 0,
    "skill_name" : "�������"
]),
([      "action" : "$N˫���������䣬��������$n��һʽ��������̶�������ֻ��Ƴ�ָ��
��ӿϮ��$n��$l",
    "force" : 200,
    "dodge" : 5,
    "damage_type" : "����",
    "lvl" : 12,
    "skill_name" : "������̶"
]),
([      "action" : "$N������ȭ���ƣ�����Ť�������ߣ�һʽ�����߾��ɡ������Ҳ��ã�
����$n��$l",
    "force" : 250,
    "dodge" : 15,
    "damage_type" : "����",
    "lvl" : 24,
    "skill_name" : "���߾���"
]),
([      "action" : "$Nһʽ��������ɽ�������ֳ�أ�����ǰ̽���ָ����$n��$l",    
    "force" : 300,
    "dodge" : -5,
    "damage_type" : "����",
    "lvl" : 36,
    "skill_name" : "������ɽ"
]),
([      "action" : "$Nʹһʽ����������������Ӱ��ò���������$n����͵�����$n��
$l",
    "force" : 350,
    "dodge" : 10,
    "damage_type" : "����",
    "lvl" : 48,
    "skill_name" : "��������"
]),
([      "action" : "$N���۴󿪴��أ���һ������һʽ���ض�ɽҡ��������͸����˫�ֿ�
��һ��������������������$n��$l",
    "force" : 400,
    "dodge" : 5,
    "damage_type" : "����",
    "lvl" : 60,
    "skill_name" : "�ض�ɽҡ"
]),
([      "action" : "$N������������Ʈ����˫�������Ķ���һʽ��ˮ�����¡����Ӹ���
�£����಻������$n��$l",
    "force" : 450,
    "dodge" : 20,
    "damage_type" : "����",
    "lvl" : 72,
    "skill_name" : "ˮ������"
]),
([      "action" : "$N�ڿն���˫�ƺ�һ��ʮָ�繳��һ�С�̩ɽѹ����������$n�Ļ�
�䣬�Ƶ������Ѽ�",
    "force" : 500,
    "dodge" : 25,
    "damage_type" : "����",
    "lvl" : 84,
    "skill_name" : "̩ɽѹ��"
])
});

int valid_enable(string usage) { return usage=="finger" ||  usage=="parry"; }   

int valid_combine(string combo) { return combo=="jinding-zhang"; }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail(HIC"�����ָѨ��������֡�\n"NOR);
    if ((int)me->query_skill("linji-zhuang", 1) < 20)
   return notify_fail("����ټ�ʮ��ׯ��򲻹����޷�ѧ���ָѨ����\n
")
;    if ((int)me->query("max_neili") < 100)
   return notify_fail("�������̫�����޷������ָѨ����\n");
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
    level = (int)me->query_skill("tiangang-zhi", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
    return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
   return notify_fail("�������̫���ˣ��޷������ָѨ����\n");
    me->receive_damage("qi", 20);
    return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tiangang-zhi/" + action;
}
