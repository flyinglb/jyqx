// shaolin-shenfa.c ������
inherit SKILL;
string *dodge_msg = ({
"$nһʽ��"+HIG+"һέ�ɽ�"+NOR+"����ǰ��Žż�Ÿ��࿿��������������ˮ�㻬�����ࡣ\n",
"$nһʽ��"+WHT+"�����Ӳ�"+NOR+"����˫��ǰ�죬ȫ������ƽ�ɣ���ʱ������$N���������ơ�\n",
"$nһʽ��"+CYN+"�Ʋ�����"+NOR+"�����㲻�����ֲ�̧��һת�ۼ���Ƶ���$N�����\n",
"$nһʽ��"+MAG+"����Ӱ"+NOR+"����һת��䣬����˷�Ʈ����������$n����Ӱ����$N������롣\n",
"$nһʽ��"+HIY+"��������"+NOR+"����ȫ���ֱ���εض����ڰ����һת�����䵽����Զ�ĵط���\n",
"$nһʽ��"+BLU+"����˫��"+NOR+"���������������������ݷ����У���$Nͷ����Ծ������\n",
"$nһʽ��"+RED+"������ˮ"+NOR+"����˫�ŵ�أ�ȫ��Ϊһ����Ӱ����������$N���˼�ת��\n",
"$nһʽ��"+HIR+"�ɷ�鳲"+NOR+"�������������ݰ㼱ת�������γ�һ�������У���$N������䣬�������á�\n",
});
int practice_level(){   return 60;  }
int valid_enable(string usage)
{
    return usage == "dodge";
}
int valid_learn(object me)
{
    if (me->query_skill("dodge", 1) <=me->query_skill("shaolin-shenfa", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
string query_dodge_msg(string limb,object me)
{
        me->set_temp("fight/dodge",me->query_skill("shaolin-shenfa",1)/2);
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    if( (int)me->query("qi") < 40 )
        return notify_fail("�������̫���ˣ���������������\n");
    me->receive_damage("qi", 30);
    return 1;
}
