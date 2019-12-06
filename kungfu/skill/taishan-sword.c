// taishan-sword.c
// Modified by Java Sep.1998
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "name":    "������",
        "action":  "$N����$wбָ���£�������ָ������ָ��������һ�����壬�ն���ȭ����
��Ĵָ������ζ�ʳָ��������ָȫչ����������Ĵָ����ʳָ��������
ָ��Ȼ������$w���Ⱪ������$n��$l��ȥ",
        "dodge":    50,
        "damage":  170,
        "damage_type":  "����"
]),
([      "name":    "��������",
        "action":  "$N����$wһ�Σ����һ���������һ�С��������ơ���ת����������
��΢����$w��$nбб��ȥ",
        "dodge":   -70,
        "damage":  120,
        "damage_type":  "����"
]),
([      "name":    "������",
        "action":  "$N����$wȦת��һ�С������ա�ȥ���漲�������������$n��$l",
        "dodge":   -40,
        "damage":   90,
        "damage_type":  "����"
]),
([      "name":    "̩ɽʮ����",
        "action":  "$Nչ�����ƣ����潣�ߣ����һ�գ��ұ�һ�䣬ԽתԽ�����͵�
$w���Ⱪ����һ�С�̩ɽʮ���̡���$n$l��ȥ",
        "dodge":   -40,
        "damage":  140,
        "damage_type":  "����"
]),
([      "name":    "����",
        "action":  "$N����$wٿ�ش̳���һ���彣��ÿһ���Ľ��нԲ�Ȼ�й��⡣����
���ӣ��ڲ���䣬���ǡ����򽣡�",
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
        return notify_fail("�������������û�а취��̩ɽ������\n");
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
        return notify_fail("�����������������û�а취��ϰ̩ɽ������\n");
    me->receive_damage("qi", 30);
    me->add("neili", -5);
    write("�㰴����ѧ����һ��̩ɽ������\n");
    return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
        return __DIR__"taishan-sword/" + action;
}
