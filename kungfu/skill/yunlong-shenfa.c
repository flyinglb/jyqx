// yunlong-shenfa ������
inherit SKILL;
string *dodge_msg = ({
"$nһʽ��"+YEL+"���ڻ�Ծ"+NOR+"��������һת���͵�����һ��,�����$N�Ĺ��ơ�\n",
"$nһʽ��"+HIM+"ɳ�����"+NOR+"����˫��������󣬲������������״�$N��ǰ�����\n",
"$nһʽ��"+WHT+"����ͬ��"+NOR+"�������˷�����һ�����Ƶ���$N�����\n",
"$nһʽ��"+CYN+"��������"+NOR+"�������������һ�ˣ������ù���$N���������ơ�\n",
"$nһʽ��"+MAG+"���Ĳ���"+NOR+"��������һ�����һ�Σ�������Ʈ����Զ��\n",
"$nһʽ��"+GRN+"��ӥ����"+NOR+"����������һֻ��ӥ������һ����$N����ǰ�ɹ���\n",
"$nһʽ��"+WHT+"��������"+NOR+"�������İεض����ڰ����һת�����䵽����Զ�ĵط���\n",
"$nһʽ��"+HIR+"�������"+NOR+"����ȫ��Ϊһ����Ӱ������һ���շ��������Ʈ���ұߡ�\n",
"$nһʽ��"+HIG+"��������"+NOR+"�������ζ��ر��Ʈ����������$N�޷����塣\n",
"$nһʽ��"+BLU+"��������"+NOR+"��������һ����ʸ������ٿ�İεض�����$N�������ӡ�\n",
});
int practice_level(){   return 100;  }
int valid_enable(string usage)
{
    return usage == "dodge";
}
int valid_learn(object me)
{
    if (me->query_skill("dodge", 1) <=me->query_skill("yunlong-shenfa", 1))
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
    me->receive_damage("qi", 20);
    return 1;
}
