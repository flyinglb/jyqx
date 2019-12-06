// lanhua-shou.c -������Ѩ��
// Modified by Venus Oct.1997
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N������ָ�ֿ���΢΢һ�����ٲ�£����һ����һʽ�������Ƶ�����
����$n������ҪѨ",
    "force" : 150,
    "dodge" : 5,
    "damage_type" : "����",
    "lvl" : 0,
    "skill_name" : "�����Ƶ�"
]),
([  "action" : "$N��������$n��һʽ�����Ʊ��¡���������ָ������������$n����ǰ
��Ѩ",
    "force" : 160,
    "dodge" : 5,
    "damage_type" : "����",
    "lvl" : 10,
    "skill_name" : "���Ʊ���"
]),
([  "action" : "$Nʹһʽ�������������������鹥�����ֲ�ָбǰ����������$n�ļ�
��Ѩ",
    "force" : 170,
    "dodge" : 15,
    "damage_type" : "����",
    "lvl" : 20,
    "skill_name" : "��������"
]),
([  "action" : "$N���ƻ��أ�΢΢�������ƹ��ϣ�һʽ������ŪӰ������������$n
����ͻѨ",
    "force" : 190,
    "dodge" : -5,
    "damage_type" : "����",
    "lvl" : 30,
    "skill_name" : "����ŪӰ"
]),
([  "action" : "$Nʹһʽ���������塹����Ӱ����������$n����͵�����$n�Ĵ�׵
Ѩ",
    "force" : 210,
    "dodge" : 10,
    "damage_type" : "����",
    "lvl" : 42,
    "skill_name" : "��������"
]),
([  "action" : "$N���������������ϵ�����ǰ������ָ�η��ϣ�΢��һ������һʽ��
�����뷼����˫���������һ��������������������$n�Ļ��ǡ���ᡢ�Ϲ�������Ѩ",
    "force" : 240,
    "dodge" : 5,
    "damage_type" : "����",
    "lvl" : 54,
    "skill_name" : "�����뷼"
]),
([  "action" : "$N����ƮƮ������Ծ��һʽ����Ӱ���㡹���Ӹ����£�����һ����
������$n�İٻ��Ѩ",
    "force" : 270,
    "dodge" : 20,
    "damage_type" : "����",
    "lvl" : 66,
    "skill_name" : "��Ӱ����"
]),
([  "action" : "$N����ʩչ����������Բ����˫�ּ�����һ�����ľ�������$n������
�¸���ҪѨ",
    "force" : 300,
    "dodge" : 25,
    "damage_type" : "����",
    "lvl" : 80,
    "skill_name" : "������Բ"
])
});

int valid_enable(string usage) { return usage=="hand" ||  usage=="parry"; }     
int practice_level(){   return 100;  }
int valid_combine(string combo) { return combo=="tanzhi-shentong"; }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
       return notify_fail(HIC"��������Ѩ�ֱ�����֡�\n"NOR);
    if ((int)me->query_skill("bibo-shengong", 1) < 20)
       return notify_fail("��ı̲��񹦻�򲻹����޷�ѧ������Ѩ�֡�\n");
    if ((int)me->query("max_neili") < 200)
       return notify_fail("�������̫�����޷���������Ѩ�֡�\n");
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
    level = (int)me->query_skill("lanhua-shou", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
    return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
       return notify_fail("�������̫���ˣ��޷���������Ѩ�֡�\n");
    me->receive_damage("qi", 25);
    return 1;
}

string perform_action_file(string action)
{
        return __DIR__"lanhua-shou/" + action;
}

