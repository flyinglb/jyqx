// yanfly.c ��˫��
inherit SKILL;
string *dodge_msg = ({
    "$nһ����"+MAG+"����˫��"+NOR+"��������$N�Ĺ���Ʈ�𣬴��ݶ����һ�С�\n",
    "$nʹ��һ�С�"+MAG+"���ഩ��"+NOR+"������Ȼ�������࣬���$N���˸��ա�\n",
    "$n����һҡ���ó�������Ӱ��һ�С�"+GRN+"������ˮ"+NOR+"�������$N�Ĺ��ơ�\n",
    "$nһ�С�"+BLU+"����Ͷ��"+NOR+"������Ծ��ٿ��������$N���\n",
    "$n��һҡ����һ�Σ�һ�С�"+MAG+"�������"+NOR+"��������������\n",
});
int practice_level(){   return 60;  }
int valid_enable(string usage) 
{ 
    return (usage == "dodge") ;
}
int valid_learn(object me)
{
    if (me->query_skill("dodge", 1) <=me->query_skill("yan-shuangfei", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1; }
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
        if( (int)me->query("qi") < 30 )
            return notify_fail("�������̫���ˣ���������˫�ɡ�\n");
        if (me->query_skill("yan-shuangfei", 1) < 30)
            me->receive_damage("qi", 10);
        me->receive_damage("qi", 20);
        return 1;
}
