// feiyan-huixiang.c �������
// modified by Venus Oct.1997
// pyrobat-steps.c

inherit SKILL;

string *dodge_msg = ({
    "����$n����Ʈ��������һ�ݣ�һ�С�����Ͷ�֡�����������ıܿ���һ����\n",
    "$n������ת��һʽ��ѩ�����衹��ٿ����һ��Ʈ�����ߣ��ܹ�����һ�С�\n",
    "����$n����һ�ã�ʹ����������Ʈ����$N��һ�����˸��ա�\n",
    "ȴ��$n�㲻��أ�һ�С����Ƽ��������ε�����һת�������������ߣ����˿�ȥ��\n",
    "$n���һ���ҽű�����������һ�Σ�һ�С�һ�׳��졹���������ɵرܿ�����һ�С�\n"
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
    if( (int)me->query("qi") < 30 )
   return notify_fail("�������̫���ˣ��������������......\n");
    me->receive_damage("qi", 30);
    return 1;
}
