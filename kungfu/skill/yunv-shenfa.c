// yunv-shenfa.c ��Ů��

inherit SKILL;

string *dodge_msg = ({
        "����$n����һת��ʹ������Ѭ΢�ȡ�����ز������ܿ�����һ�С�\n",
        "$nһ�С���ʩ�ɴ����������ת��ٿ����һ��Ų�������ߡ�\n",
        "$n����Ʈ����հ֮��ǰ�������ں�ȴ�ǡ�������̨��������\n",
        "$nʹ��������岨����������ˮ�滬��һ�㣬���λ��˿�ȥ��\n",
        "����$n����ӰƮƮ���죬��˿������������һʽ����ɽ���ء�������\n"
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
                return notify_fail("�������̫���ˣ���������Ů����\n");
        me->receive_damage("qi", 25);
        return 1;
}
