
inherit SKILL;
string *dodge_msg = ({
    "$n�������ĵ���������һ�����պñܹ�$N���������ơ�\n",
    "����$n����������������һ���������$N��һ�С�\n",
        "����$n����Ʈ��������һ�ݣ����ѱܿ���\n",
        "$n������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
        "����$n����һ�ã�$N��һ�����˸��ա�\n",
        "ȴ��$n�㲻��أ����Դܿ����ߣ����˿�ȥ��\n",
        "$n����΢�Σ��о����յرܿ���$N��һ�С�\n",
        "$n�������ĵ�����һ������ͷ΢��,�����ܹ���$N��һ�С�\n"
});
int valid_enable(string usage) { return (usage == "dodge"); }
int practice_level(){   return 60;  }
int valid_learn(object me) 
{
    if (me->query_skill("dodge", 1) <=me->query_skill("yixingbu", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
string query_dodge_msg(string limb,object me)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
        if( (int)me->query("qi") < 50 )
                return notify_fail("�������̫���ˣ����������β�����\n");
        me->receive_damage("qi", 30);
        return 1;
}
