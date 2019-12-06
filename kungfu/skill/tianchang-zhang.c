// tianchang-zhang.c �쳤�Ʒ�
// modified by Venus Oct.1997
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$Nһʽ"+HIC"��Ǳ��Ĭ����"NOR+"�������ȷ������ƺ���������$n��
$l",
    "force" : 160,
    "dodge" : 30,
    "damage_type" : "����",
    "lvl" : 0,
    "skill_name" : "Ǳ��Ĭ��"
]),
([      "action" : "$N������ϣ�һ��"+HIB"�����Ǵ��¡�"NOR+"��˫�����������$n��
$l",
    "force" : 180,
    "dodge" : 25,
    "damage_type" : "����",
    "lvl" : 9,
    "skill_name" : "���Ǵ���"
]),
([      "action" : "$N����Ծ��ʹ��"+BLU"�������ܲ���"NOR+"������������Ӱ������
$n��$l",
    "force" : 200,
    "dodge" : 20,
    "damage_type" : "����",
    "lvl" : 18,
    "skill_name" : "�����ܲ�"
]),
([      "action" : "$N�����˿�һ��������һʽ"+HIW"����������"NOR+"��������������
���ƣ�������������İ���Ϯ��$n��$l",
    "force" : 230,
    "dodge" : 15,
    "damage_type" : "����",
    "lvl" : 27,
    "skill_name" : "��������"
]),
([      "action" : "$N˫��ͻȻһ���������ƿ���һʽ"+HIW"���������ߡ�"NOR+"���Ƴ�����
��������$n��$l",
    "force" : 260,
    "dodge" : 10,
    "damage_type" : "����",
    "lvl" : 36,
    "skill_name" : "��������"
]),
([      "action" : "$Nб�ﴩ����ʹ��"+RED"�������ƻ�"NOR+"��˫��Ĭ���ھ���$n���ؿ�
ƽ�Ƴ�һ��������Ϣ�����ȵľ���",
    "force" : 300,
    "dodge" : 5,
    "damage_type" : "����",
    "lvl" : 45,
    "skill_name" : "�����ƻ�"
]),
([      "action" : "$Nʩչ��"+HIR"����ζ���"NOR+"����������ǰ΢΢һ�ڣ�������һ�̣�
���������͵�һ�ƣ��������������һ����������$n���ؿ�",
    "force" : 350,
    "dodge" : -5,
    "damage_type" : "����",
    "lvl" : 54,
    "skill_name" : "��ζ���"
]),
([      "action" : "$Nʹһʽ"+WHT"���ºڷ�ߡ�"NOR+"��˫�Ƶ�������������������
$n��$l",
    "force" : 400,
    "parry" : 25,
    "dodge" : 20,
    "damage_type" : "����",
    "lvl" : 63,
    "skill_name" : "�ºڷ��"
]),
([      "action" : "$Nʹ��"+HIW"������ȸߡ�"NOR+"��˫�ƻ���������գ�������Ȼ�����ջأ�
��$n�͵��Ƴ�",
    "force" : 450,
    "parry" : 10,
    "dodge" : 15,
    "damage_type" : "����",
    "lvl" : 72,
    "skill_name" : "����ȸ�"
]),
([      "action" : "$N����Ǳ����ʩչ��"+HIY"������ͬ�ԡ�"NOR+"��˫��б���������ҿ�������
������������$n��$l",
    "force" : 500,
    "parry" : 20,
    "dodge" : 5,
    "damage_type" : "����",
    "lvl" : 81,
    "skill_name" : "����ͬ��"
]),
([      "action" : "$N˫�ƽ���һ����������һ����ʹ��"+HIY"���������ԡ�"NOR+"�����������ϣ�
�����£�����ʯ��ط�������$n",
    "force" : 580,
    "parry" : 5,
    "dodge" : -5,
    "damage_type" : "����",
    "lvl" : 90,
    "skill_name" : "��������"
])
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }  

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail(HIC"���쳤�Ʒ�������֡�\n"NOR);
    if ((int)me->query("max_neili") < 80)
   return notify_fail(HIG"�������̫�����޷����쳤�Ʒ���\n"NOR);
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
    level = (int)me->query_skill("tianchang-zhang", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
    return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
   return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
   return notify_fail("��������������쳤�Ʒ���\n");
    me->receive_damage("qi", 25);
    return 1;
}
