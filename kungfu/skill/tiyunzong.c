// tiyunzong.c ������
// written by Xiang
inherit SKILL;
string *dodge_msg = ({
    "ֻ��$nһ�С�"+WHT+"�׺׳���"+NOR+"�����������ϱ�ֱ���������࣬�����$N��һ�С�\n",
    "$nһ����"+RED+"���ӷ���"+NOR+"��������ݳ�����֮Զ���ܿ���$N���������ơ�\n",
    "$nʹ����"+MAG+"����չ��"+NOR+"������һ��ƮȻ�ݳ��������ŵء�\n"
});
int valid_enable(string usage) { return (usage == "dodge"); }
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    if (me->query_skill("dodge", 1) <=me->query_skill("tiyunzong", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
string query_dodge_msg(string limb,object me)
{
        if (me) me->set_temp("fight/dodge",random(2*me->query_skill("tiyunzong",1)));
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("�������̫���ˣ������������ݡ�\n");
        me->receive_damage("qi", 30);
        return 1;
}

