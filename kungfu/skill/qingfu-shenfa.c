// qingfu-shenfa.c ������
// pal 1997.05.26
inherit SKILL;
string *dodge_msg = ({
    "ֻ��$nһ�С�"+RED+"����Ǭ��"+NOR+"�������ζ�Ȼ���𣬶����$N��һ�С�\n",
    "$nһʽ��"+YEL+"��������"+NOR+"�������λζ�����һ��Ʈ�����ܿ���$N��һ�С���\n"
    "$nʹ����"+BLU+"���츣��"+NOR+"����һ�����Ľ��󷭳����ܿ���$N���������ơ�\n",
    "$nһ�С�"+HIW+"��������"+NOR+"����������ת��$Nֻ����ǰһ����$n������$N�����\n",
});
int practice_level(){   return 60;  }
int valid_enable(string usage)
{
    return usage == "dodge";
}
int valid_learn(object me)
{
    if (me->query_skill("dodge", 1) <=me->query_skill("qingfu-shenfa", 1))
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
                return notify_fail("�������̫���ˣ���������������\n");
        me->receive_damage("qi", 30);
        return 1;
}
