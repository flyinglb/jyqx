// yaoming-dodge ��ڤ��
inherit SKILL;
string *dodge_msg = ({
"$nһʽ��"+YEL+"¥�۷ɾ�"+NOR+"�������ο����һĨ����,�����$N�Ĺ��ơ�\n",
"$nһʽ��"+HIM+"���չ��"+NOR+"������Ȼ�����ΰ����ڿ���һ��ת�ۣ��������ɵ���������֮�⣬���״�$N��ǰ�����\n",
"$nһʽ��"+WHT+"̤ѩ�޺�"+NOR+"�����������������ѻ��˷��򣬼�ֱ��ͬ����һ�����Ƶ���$N�����\n",
"$nһʽ��"+CYN+"����ת"+NOR+"��������һ�ۣ����н�������֮�����������㣬�����ù���$N���������ơ�\n",
"$nһʽ��"+MAG+"��ת����"+NOR+"������̤���ǣ����ΰ��ԣ���ʱ�ó�ǧ����Ӱ��Ʈ����Զ��\n",
"$nһʽ��"+MAG+"�������"+NOR+"�����������ף����Ƶ�������������ŭ����Ʈ����Զ��\n",
});
int practice_level(){   return 150;  }
int valid_enable(string usage)
{
    return usage == "dodge";
}
int valid_learn(object me)
{
    if (me->query_skill("dodge", 1) <=me->query_skill("yaoming-dodge", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
string query_dodge_msg(string limb,object me)
{
        me->set_temp("fight/dodge",me->query_skill("yaoming-dodge",1)/2);
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
    if( (int)me->query("qi") < 60 )
        return notify_fail("�������̫���ˣ���������ڤ����\n");
    me->receive_damage("qi", 60);
    return 1;
}
