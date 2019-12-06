// songshan-sword.c
// Modified by Java Sep.1998
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "name":    "��������",
        "action":  "$N����$wһ�����ٽ���������������ʹһ�С��������ڡ�����
��ϵ���ڵ���ɽ����",
        "dodge":    50,
        "damage":  170,
        "damage_type":  "����"
]),
([      "name":    "ǧ������",
        "action":  "$N����$wͻȻ�佣��һ�£�����һ���׺磬������ΰ������Ʈ�ݣ�
������ɽ�����ľ�Ҫ���ڣ�һ�С�ǧ����������$n$lֱ�̹���",
        "dodge":   -70,
        "damage":  120,
        "damage_type":  "����"
]),
([      "name":    "���両��",
        "action":  "$N����$wͻȻ�佣��һ�£�һ�С����両�࡯����һ����⣬��
׳�ۻ룬��$n$lֱ�̹���",
        "dodge":   -70,
        "damage":  120,
        "damage_type":  "����"
]),
([      "name":    "������",
        "action":  "$N����$w����һ�£�һ�С������ء��������࣬������ΰ����
$n$lֱ�̹���",
        "dodge":   -70,
        "damage":  120,
        "damage_type":  "����"
]),
([      "name":    "���ż�ɽ",
        "action":  "$N��������һ�֣�����$w�����ӳ���ʹ������ɽ�ɽ��������ż�
ɽ��",
        "dodge":   -70,
        "damage":  120,
        "damage_type":  "����"
]),
([      "name":    "������ɽ",
        "action":  "$N����$w���϶��µ���$nֱ����ȥ��һ�С�������ɽ��������ʯ
���쾪�����ƣ�����ɽ����֮�������ӵ����쾡��",
        "dodge":   -40,
        "damage":   90,
        "damage_type":  "����"
]),
([      "name":    "��������",
        "action":  "$N����$wˢ��һ��������Ҽ�����ȥ������һ����ɽ����
�ڽ���������������������$w�԰���к��������������ֱ����
������һ������һ��",
        "dodge":   -40,
        "damage":  140,
        "damage_type":  "����"
]),
});

int valid_learn(object me)
{
    object ob;
//   if( (string)me->query("gender") != "Ů��" )
//   return notify_fail("��������������ֻ��Ů�Ӳ��������书��\n");
    if( (int)me->query("max_neili") < 50 )
        return notify_fail("�������������û�а취����ɽ������\n");
//   if( (string)me->query_skill_mapped("force")!= "zixia-shengong")
//        return notify_fail("��ɽ�������������ϼ�񹦲�������\n");
    if( !(ob = me->query_temp("weapon"))
    ||      (string)ob->query("skill_type") != "sword" )
        return notify_fail("���������һ�ѽ�������������\n");

    return 1;
}

int valid_enable(string usage)
{
    return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    if( (int)me->query("qi") < 30
    ||      (int)me->query("neili") < 5 )
        return notify_fail("�����������������û�а취��ϰ��ɽ������\n");
    me->receive_damage("qi", 30);
    me->add("neili", -5);
    write("�㰴����ѧ����һ����ɽ������\n");
    return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
        return __DIR__"songshan-sword/" + action;
}
