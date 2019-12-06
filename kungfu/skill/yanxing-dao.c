// yanxing-dao.c ���е���
// modified by Venus Oct.1997
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "skill_name" : "���־�",
    "action" : "$Nʹ�������־����������������е�бб������һ���׹�����$n��
$l",
    "force" : 170,
    "dodge" : 30,
    "damage_type" : "����",
    "lvl" : 0
]),
([      "skill_name" : "���־�",
    "action" : "$Nʹ�������־��������ֻ��������һ�������ֵ���ͷֱ��������һ
����âֱ��$n��$l����",
    "force" : 240,
    "dodge" : 15,
    "damage_type" : "����",
    "lvl" : 10
]),
([      "skill_name" : "���־�",
    "action" : "$Nʹ�������־��������ֺ󳷣���б���мܣ�˳���¶磬������Ҹ��
��������ס�Է����󣬵��ⲻָͣ��$n��$l",
    "force" : 300,
    "dodge" : 5,
    "damage_type" : "����",
    "lvl" : 20
]),
([      "skill_name" : "���־�",
    "action" : "$Nʹ�������־�����������ϣ�����ͻ�������ִ����Է�$n���У���
�ֵ��͵ص�������$n���ڵ�����",
    "force" : 350,
    "dodge" : -5,
    "damage_type" : "����",
    "lvl" : 30
]),
([      "skill_name" : "���־�",
    "action" : "$Nʹ�������־������������էȻһ�������ּ��ٲ�ס$n���֣�����
��һ�������磬������ס$n��$l",
    "force" : 400,
    "dodge" : 20,
    "damage_type" : "����",
    "lvl" : 40
]),
([      "skill_name" : "���־�",
    "action" : "$Nʹ�������־����������䣬����Ʈ����׽����͸����$n�ۻ�����
֮�ʣ����ֵ��ⷴ����$n��$l",
    "force" : 425,
    "dodge" : 15,
    "damage_type" : "����",
    "lvl" : 50
]),
([      "skill_name" : "̽�־�",
    "action" : "$Nʹ����̽�־�������ӯ��һ����ת�����ų��������ֵ�������ǰ
��ֱ��$n��$l",
    "force" : 450,
    "dodge" : 20,
    "damage_type" : "����",
    "lvl" : 60
]),
([      "skill_name" : "���־�",
    "action" : "$N����ʹ�������־�����������ת�������Ķ�������$n��ת�����е�
��������$n��ȫ���������Լ����µĵ����У��޴�����",
    "force" : 500,
    "dodge" : 25,
    "damage_type" : "����",
    "lvl" : 70
]),
([      "skill_name" : "���־�",
    "action" : "$N����ʹ�������־���������ص�������$nǰ����һ�������ⶸ�֣�
����ǧ���������ڶ���",
    "force" : 500,
    "dodge" : 25,
    "damage_type" : "����",
    "lvl" : 80
]),
([      "skill_name" : "���־�",
    "action" : "$N����ʹ�������־�����˫�ֽ��棬������߫��$nʵ�ڿ����嵶����
���˺����ܣ�ֻ��һ����ֱ�ƹ���",
    "force" : 500,
    "dodge" : 25,
    "damage_type" : "����",
    "lvl" : 90
]),
});

int valid_enable(string usage) { return usage=="blade" ||  usage=="parry"; }    

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 50)
   return notify_fail("�������������\n");
    if ((int)me->query_skill("linji-zhuang", 1) < 20)
   return notify_fail("����ټ�ʮ��ׯ���̫ǳ��\n");
    if ((int)me->query_skill("blade", 1) < (int)me->query_skill("yanxing-dao
", 1) )
   return notify_fail("��Ļ����������̫ǳ��\n");
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
    level = (int)me->query_skill("yanxing-dao", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
    return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
   return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
   return notify_fail("����������������е���\n");
    me->receive_damage("qi", 10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"yanxing-dao/" + action;
}
