// huashan-shenfa.c ��ɽ��
inherit SKILL;
string *dodge_msg = ({
"$nһʽ��"+RED+"��������"+NOR+"���������������������ݷ����У���$Nͷ����Ծ������\n",
"$nһʽ��"+YEL+"������ϼ"+NOR+"������һ����磬�滺��������$N���������ơ�\n",
"$nһʽ��"+MAG+"��س���"+NOR+"������ӯ��һԾ��һת�ۼ���Ƶ���$N�����\n",
"$nһʽ��"+HIY+"ȴ�����"+NOR+"����һת��䣬���Ʈ����һ��Զ\n",
"$nһʽ��"+HIG+"���ճ���"+NOR+"����ȫ���ֱ���εض����ڰ����һת�����䵽����Զ�ĵط���\n",
"$nһʽ��"+HIW+"������"+NOR+"����������һֻ�����������ˮ�ػ������ࡣ\n",
"$nһʽ��"+GRN+"��������"+NOR+"����˫�ŵ�أ�ȫ��Ϊһ����Ӱ����������$N���˼�ת��\n",
"$nһʽ��"+HIR+"��������"+NOR+"�������ζ��ر��Ʈ����������$N�޷����塣\n",
"$nһʽ��"+BLU+"��������"+NOR+"��������һ����ʸ������Χ��$N���ٵ������˼�Ȧ��\n",
});
int practice_level(){   return 60;  }
int valid_enable(string usage)
{
    return usage == "dodge" ;
}
int valid_learn(object me)
{
    if (me->query_skill("dodge", 1) <=me->query_skill("huashan-shenfa", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
string query_dodge_msg(string limb,object me)
{
        me->set_temp("fight/dodge",me->query_skill("huashan-shenfa",1)/2);
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
    if( (int)me->query("qi") < 40 )
        return notify_fail("�������̫���ˣ���������ɽ����\n");
    me->receive_damage("qi", 30);
    return 1;
}
