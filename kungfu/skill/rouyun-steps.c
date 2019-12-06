// rouyun-steps.c  ���Ʋ���
// modified by Venus Oct.1997
// Made by deaner
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" :    "$nʹһʽ"+HIW"�����к�Ӱ��"NOR+"����������������ߣ������$N��һ�С�\n",
    "dodge"  : 20
]),
([      "action" :    "$n����ƮƮ��ʹ��һʽ"+MAG"���Ʋ�Ʈ����"NOR+"���ܹ���$N�Ĺ�����\n",
    "dodge"  : 30
]),
([      "action" :    "$nʹ��һʽ"+HIB"���������ơ�"NOR+"��$N��ǰ��û��$n����Ӱ��\n",
    "dodge"  : 40
]),
([      "action" :    "$nʩչ��һʽ"+HIG"�����겻����"NOR+"����Ӱ���ϣ���ǧ��һ��������$N�Ĺ��ơ�\n",
    "dodge"  : 50
]),
([      "action" :    "$n����ƮƮ��һʽ"+HIY"������ϼε��"NOR+"������ر��˿�ȥ��\n",
    "dodge"  : 60
]),
([      "action" :    "$n����ʹ��һʽ"+YEL"���ƺ�������"NOR+"�����绬����΢����Ӱ���ܿ���$N�Ĺ�����\n",
    "dodge"  : 75
]),
([      "action" :    "$n����ʹһʽ"+BLU"����Ӱ��ǧ��"NOR+"�����κ������ˣ�������ң�$N�Ĺ�����Ȼ��Ч��\n",
    "dodge"  : 90
])
});

mapping query_action(object me, object weapon)
{
    int zhaoshu, level;

    zhaoshu = sizeof(action);
    level   = (int) me->query_skill("rouyun-steps",1);

    if (level < 60 )
   zhaoshu--;

    if (level < 50 )
   zhaoshu--;

    if (level < 40 )
   zhaoshu--;
    return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
    return (usage == "dodge") || (usage == "move");
}

int valid_learn(object me)
{
    if ((int)me->query_skill("lingyuan-xinfa", 1) < 10)
   return notify_fail(HIC"�����Ԫ�ķ����̫ǳ��\n"NOR);
    if ((string)me->query("gender") == "����" )
   return notify_fail(HIY"��������Ĳ�����ү��ѧ�����\n"NOR);
    return 1;
}

string query_dodge_msg(string limb)
{
    object me, ob;
    mapping action;

    me = this_player();
    action = query_action(me, ob);

    return action["action"];
}

int practice_skill(object me)
{
    if( (int)me->query("qi") < 35 )
   return notify_fail(HIC"�������̫���ˣ����������Ʋ�����\n"NOR);
    if (me->query_skill("rouyun-steps", 1) < 20)
   me->receive_damage("qi", 10);
    else if (me->query_skill("rouyun-steps", 1) < 60)
   me->receive_damage("qi", 20);
    else
   me->receive_damage("qi", 30);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"rouyun-steps/" + action;
}
