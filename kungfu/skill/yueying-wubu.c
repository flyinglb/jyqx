// yueying-wubu.c  ��Ӱ�貽
inherit SKILL;
string *dodge_msg = ({
"$n����һ�Σ�����һŤ��һ�С�"+MAG+"�Ǻ�����"+NOR+"�������ض���\n",
"$nһ�С�"+HIR+"�辡�һ��ȵ׷�"+NOR+"����$Nֻ����ǰһ����������$n����Ӱ��\n",
"$nһ�С�"+BLU+"ɨ�����Ʒ粻��"+NOR+"��������΢�Σ��о����յرܿ���$N��һ�С�\n",
"ֻ��$n�������һ����һ�С�"+RED+"����º�Ӱ"+NOR+"�����󵴶�������һ�ԡ�\n" ,
"$nһ�С�"+GRN+"����Ū��Ӱ"+NOR+"�������䷭�ɣ����$N��һ�С�\n",
"ȴ��$n��"+HIW+"���꽭��һ�ط�"+NOR+"�����������һ�����ۣ��������ۡ�\n",
"����$nһ����"+BLU+"��ˮ�仨��ȥҲ"+NOR+"��������һ�ã�$N��һ�����˸��ա�\n",
"ֻ��$nһ�С�"+HIW+"���ִ���ˮ�޺�"+NOR+"�����������Σ����������ת���˳����ɿ��⡣\n",
"$nϢ���������������һ�С�"+HIB+"��������Ӱ�ڲ�"+NOR+"��������ƮȻ����\n",
});
int practice_level(){   return 90;  }
int valid_enable(string usage) { return (usage == "dodge"); }
int valid_learn(object me)
{
    if (me->query_skill("dodge", 1) <=me->query_skill("yueying-wubu", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
string query_dodge_msg(string limb,object me)
{
        me->set_temp("fight/dodge",me->query_skill("yueying-wubu",1)/2);
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
    if( (int)me->query("qi") < 45 )
        return notify_fail("�������̫���ˣ������������貽��\n");
    me->receive_damage("qi", 35);
    return 1;
}
