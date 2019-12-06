// zhaixinggong.c based on xiaoyaoyou.c
inherit SKILL;
string *dodge_msg = ({
    "$nһ����"+MAG+"����ժ��"+NOR+"����Ծ�����ߣ������$N��һ�С�\n",
    "$n�������һ�ݣ�ʹ��һ�С�"+CYN+"ƮȻ����"+NOR+"�����ܹ���$N�Ĺ�����\n",
    "$nʹ����"+HIM+"������ˮ"+NOR+"����ǡ�ö����$N�Ĺ��ơ�\n",
       "$n������ת��һ�С�"+YEL+"��ת����"+NOR+"����ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
       "$n�㲻��أ�ʹ����"+MAG+"���Ǹ���"+NOR+"�������Դܿ����ߣ����˿�ȥ��\n",
       "$nһ�С�"+WHT+"֯Ů����"+NOR+"������̬����ض��˿�ȥ��\n"
});
int practice_level(){   return 60;  }
int valid_enable(string usage) 
{ 
    return (usage == "dodge") ; 
}
int valid_learn(object me)
{ 
    if (me->query_skill("dodge", 1) <=me->query_skill("zhaixinggong", 1))
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
                return notify_fail("�������̫���ˣ�������ժ�ǹ���\n");
    if (me->query_skill("zhaixinggong", 1) < 30)
            me->receive_damage("qi", 10);
    else if (me->query_skill("zhaixinggong", 1) < 60)
        me->receive_damage("qi", 20);
    else 
        me->receive_damage("qi", 30);
        return 1;
}
