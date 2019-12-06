// hengshan-sword.c
// Modified by Java Sep.1998
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([
        "action":  "$N����$w����ָ����ͻȻ���ڿ���һ������������֮�������ű���
��������������$w���Ⱪ������$n��$l��ȥ",
        "dodge":    50,
        "damage":  170,
        "damage_type":  "����"
]),
([
        "action":  "$N����$w������ȣ���Ȼ���Ƶ���$n����$n��æת������ֻ��
����������",
        "dodge":   -70,
        "damage":  120,
        "damage_type":  "����"
]),
([      "name":    "�ٱ�ǧ��",
        "action":  "$N����$w���ⶸ�������е�$w���͵ط��̣�ֱָ$n�ؿڡ���һ��
���п켫������������ã����ǡ��ٱ�ǧ�ú�ɽ����ʮ��ʽ���еľ���",
        "dodge":   -40,
        "damage":   90,
        "damage_type":  "����"
]),
([      "name":    "Ȫ��ܽ��",
        "action":  "$N�����Է�������·������$wˢ��һ����Ȫ��ܽ�ء�����$nС
����ȥ",
        "dodge":   -40,
        "damage":  140,
        "damage_type":  "����"
]),
([      "name":    "�����ϸ�",
        "action":  "$N�����Է�������·������$wˢ��һ���������ϸǡ�����$n��
ͷ��ȥ",
        "dodge":   -40,
        "damage":  140,
        "damage_type":  "����"
]),
([      "name":    "ʯ������",
        "action":  "$N����$wٿ�ش̳������ƴ����ػأ�������ã�����һ�С�ʯ����������
��$n$l��ȥ",
        "dodge":   60,
        "damage":  220,
        "damage_type":  "����"
]),
([      "name":    "��������",
        "action":  "$N����$wٿ�ش̳�����������֮���£������޶�������׽��������
һ�С�������������ָ��$n$l",
        "dodge":   60,
        "damage":  220,
        "damage_type":  "����"
]),
([      "name":    "���ף��",
        "action" : "$N����Ծ�𣬡����ף�ڡ�����$w����һ�������Ӱ��������$n��
$l",
        "dodge":   60,
        "damage":  220,
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
    write("�㰴����ѧ����һ���ɽ������\n");
    return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
        return __DIR__"hengshan-sword/" + action;
}
