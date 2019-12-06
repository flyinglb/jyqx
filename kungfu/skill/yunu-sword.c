// yunu-sword.c ��Ů����
// modified by Venus Oct.1997

#include <ansi.h>

inherit SKILL;

mapping *action = ({
    ([ "name":    "��������",
       "action":  "$Nʹһ�С��������ߡ�����̤�й�������$wֱָ$n$l",
       "dodge":   50,
       "damage":  170,
       "damage_type":  "����"
    ]),
    ([ "name":    "�����޷�",
       "action":  "$N������ת��һ�С������޷졹������һƬ��Ӱ������$n��$l",
       "dodge":   30,
       "damage":  80,
       "damage_type":  "����"
    ]),
    ([ "name":    "ҹ��ԧ��",
       "action":  "$N�趯$w��ʹ��һ�С�ҹ��ԧ�졹���������ң���˸������ֱ��$n��$l",
       "dodge":   40,
       "damage":  90,
       "damage_type":  "����"
    ]),
    ([ "name":    "֯Ů����",
       "action":  "$Nһ�����ȣ�������֯Ů���󡹣�����$w��Ϊһ�����⣬����$n��$l",
       "dodge":   40,
       "damage":  60,
       "damage_type":  "����"
    ]),
    ([ "name":    "С������",
       "action":  "$N��Ȼ����ֱ�ϣ�һ�С�С�����ˡ�������$w�������ϴ���$n��$l",
       "dodge":   50,
       "damage":  90,
       "damage_type":  "����"
    ]),
});

int valid_learn(object me)
{
    object ob;
   if( (string)me->query("gender") != "Ů��" )
       return notify_fail("��Ů����ʮ������ֻ��Ů�Ӳ��������书��\n");
    if( (int)me->query("max_neili") < 50 )
       return notify_fail("�������������û�а취����Ů����ʮ������\n") ;
   if( (string)me->query_skill_mapped("force")!= "zixia-shengong")
       return notify_fail("��Ů����ʮ�������������ϼ�񹦲�������\n");
   if( !(ob = me->query_temp("weapon"))
       || (string)ob->query("skill_type") != "sword" )
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
    ||  (int)me->query("neili") < 5 )
      return notify_fail("�����������������û�а취��ϰ��Ů����ʮ������\n");
    me->receive_damage("qi", 30);
    me->add("neili", -5);
    write("�㰴����ѧ����һ����Ů����ʮ������\n");
    return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
        return __DIR__"yunu-sword/" + action;
}
