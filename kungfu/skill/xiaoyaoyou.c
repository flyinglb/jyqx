// xiaoyaoyou.c
// written by Xiang
inherit SKILL;
string *dodge_msg = ({
    "$nһ����"+GRN+"���ѵ�ˮ"+NOR+"���������$N��һ�С�\n",
    "$n�������һ�ݣ�ʹ��һ�С�"+YEL+"ϸ���ɷ���"+NOR+"�����ܹ���$N�Ĺ�����\n",
    "$nʹ����"+HIR+"�黳����"+NOR+"����ǡ�ö����$N�Ĺ��ơ�\n"
        "����$n����Ʈ��������һ�ݣ����ѱܿ���\n",
        "$n������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
});
int valid_enable(string usage) 
{ 
    return (usage == "dodge"); 
}
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    if (me->query_skill("dodge", 1) <=me->query_skill("xiaoyaoyou", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("�������̫���ˣ���������ң�Ρ�\n");
        me->receive_damage("qi", 30);
        return 1;
}
