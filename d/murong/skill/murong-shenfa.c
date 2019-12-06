// yanling-shenfa.c ������

inherit SKILL;

mapping *action = ({
([      "action" : "$nһʽ�������Ϸɡ�����Žż�����ҽ���շ�����������������ˮ�㻬�����ࡣ\n",
        "dodge"  : 15
]),
([      "action" : "$nһʽ��һҶ��Ŀ����������ת��˫�Űϵض��𣬶�ʱ������$N���������ơ�\n",
        "dodge"  : 25
]),
([      "action" : "$nһʽ��˫��ַɡ�������˫������߳����ţ���ʱ�䵽$N���Ͽա�\n",
        "dodge"  : 35
]),
([  "action" : "$nһʽ�����ӳ�������ͻȻ������ǰ�ˣ���������ĳ���$N����$N������롣\n",
        "dodge"  : 45
]),
([  "action" : "$nһʽ����������������������ȫ��Χ��$N������ת����$N��æ���ң�$n���䵽����Զ�ĵط���\n",
        "dodge"  : 60
]),
([      "action" : "$nһʽ������������˫����յ�أ������ݷ����У���$Nͷ����Ծ������\n",
        "dodge"  : 75
]),
([      "action" : "$nһʽ�����ӻ�ͷ����˫�����������ƣ�����������Ʈ����ʱ����$N���������ơ�\n",
        "dodge"  : 90
]),
([ "action" : "$nһʽ�����Ϲ鳲�������������ݰ㼱ת�������γ�һ�������У���$N������䡣\n",
        "dodge"  : 100
])
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("yanling-shenfa");

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
        return usage == "dodge" || usage == "move";
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
        if( (int)me->query("jingli") < 40 )
                return notify_fail("��ľ���̫���ˣ���������������\n");
        me->receive_damage("jingli", 30);
        return 1;
}

