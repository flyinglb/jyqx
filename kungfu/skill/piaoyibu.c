// piaoyibu.c
inherit SKILL;

string *dodge_msg = ({
        "$nһ�������ضɺ�����Ծ�����ߣ������$N��һ�С�\n",
        "$n�������һ�ݣ�ʹ��һ�С������䳾�����ܹ���$N�Ĺ�����\n",
        "$nʹ��������ɳ����ǡ�ö����$N�Ĺ��ơ�\n",
        "$nһ�С�����öݡ�����̬����ض��˿�ȥ��\n"
});

int valid_enable(string usage)
{
        return (usage == "dodge") || (usage == "move");
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("�������̫���ˣ�������Ʈ�ݲ�����\n");
        if (me->query_skill("piaoyibu", 1) < 30)
                me->receive_damage("qi", 10);
        else if (me->query_skill("piaoyibu", 1) < 60)
                me->receive_damage("qi", 20);
        else
                me->receive_damage("qi", 30);
        return 1;
}

