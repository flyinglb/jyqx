// lingxu-bu ���鲽

inherit SKILL;

string *dodge_msg = ({
    "$nһʽ��ѩ�������������ӳ���һת��$Nֻ������ǰһ����ʧȥ��Ŀ�ꡣ\n",
    "$nһʽ��һ�����졹��˫�ŵ�أ�����ͻȻ�θ�����������Ʈ����$N���\n",
    "$nһʽ�����л�Ӱ��������һ�Σ���ʱ��������Ӱһ���ӳ�����$N����ǰ��\n",
    "$nһʽ���������ߡ���ƮȻ���һ�ˣ��㿪$N���������ơ�\n",
    "$nһʽ������Ʈ�졹�����弱ת����Ϊһ���׹⣬��ò����ĳ�����$N����Χ��\n",
});

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
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    if( (int)me->query("qi") < 40 )
        return notify_fail("�������̫���ˣ����������鲽��\n");
    me->receive_damage("qi", 30);
    return 1;
}

