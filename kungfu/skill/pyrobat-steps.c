// pyrobat-steps.c

inherit SKILL;

string *dodge_msg = ({
        "����$n����Ʈ��������һ�ݣ�һ�С��������١�����������ıܿ���һ����\n",
        "$n������ת��һʽ��������ҡ���ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
        "����$n����һ�ã�ʹ���������ӽ�����$N��һ�����˸��ա�\n",
        "ȴ��$n�㲻��أ�һ�С�ҹ�����������Դܿ����ߣ����˿�ȥ��\n",
        "$n����΢�Σ�ʹ�����������š����о����յرܿ���$N��һ�С�\n",
        "$n��������һ�Σ�һ�С�����ҷ�ա���һ��ת����������֮�⡣\n"
});

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
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("�������̫���ˣ���������������\n");
	me->receive_damage("kee", 30);
	return 1;
}
int effective_level() { return 10;}

int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

