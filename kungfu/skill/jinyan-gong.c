// jinyan-gong.c ���㹦
// By Lgg,1998.10

inherit SKILL;

string *dodge_msg = ({
        "$n����ڵ���һ�㣬���ΰεض��𣬶㿪����һ�С�\n",
        "ȴ����$n����һת��ͻȻת����$N�����\n",
        "$n����$N��������ʽƮ������������һƬ΢���е�����һ�㡣\n",
        "$n������һ�Ρ���һ������֪��ô�ģ��ӹ����ļ�϶�����˳�����\n",
        "$n�㲻��ص�Χ��$N����������Ȧ����$N��һ�б��˿�ȥ��\n",
        "$n����������Ȧ����������һ����Ȧ�����θ߸ߵذ���������\n",
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
        if( (int)me->query("qi") < 35 )
                return notify_fail("�������̫���ˣ�������ϰ���㹦��\n");
        me->receive_damage("qi", 25);
        return 1;
}
