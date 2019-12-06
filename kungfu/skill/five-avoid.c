// five-avoid.c ���ж�
// Modified by Venus Oct.1997
// written by deaner
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "����$n΢΢һЦ��$N��ǰˮ��������$n��ʹ��"+HIC"��ˮ�ݡ�"NOR+"
��ˮ���š�\n",
    "dodge"  : 60
]),
([  "action" : "ȴ��$n�������б��У�����·�ߵ�һ�ô�����ת�ۺ�֦Ҷ��Ϊһ�壬
$NãȻ�Ĺˣ���֪$n�Ѿ���"+HIG"��ľ�ݡ�"NOR+"�㿪������\n",
    "dodge"  : 70
]),
([  "action" : "$nԭ��һת����ʱ�������С�$N��һ���䵽�˿մ�������"+HIY"����
�ݡ�"NOR+"��\n",
    "dodge"  : 80
]),
([  "action" : "$n���ִ��һ�Ż��򣬺ȵ�"+HIR"����ݡ�"NOR+"�� ��������ʧ�ڻ
�����С�\n",
    "dodge"  : 90
]),
([  "action" : "$n����һЦ�������еı��н���һ�����ȵ�������"+HIY"����ݡ�"NOR+"����ͻȻ����ҫ�ۣ�$N
��ǰһ������һ�в�֪�䵽�˺δ���\n",
    "dodge"  : 100
]),
});

mapping query_action(object me, object weapon)
{
    int zhaoshu, level;

    zhaoshu = sizeof(action);
    level   = (int) me->query_skill("five-avoid",1);

    if (level < 200 )
       zhaoshu--;
    if (level < 150 )
       zhaoshu--;
    if (level < 100 )
       zhaoshu--;
    if (level < 70 )
       zhaoshu--;
    return action[random(zhaoshu)];
}
int valid_enable(string usage)
{
    return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
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
    if( (int)me->query("qi") < 30 )
   return notify_fail("�����������,�����������ж�.\n");
    me->receive_damage("qi", 20);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"five-avoid/" + action;
}

