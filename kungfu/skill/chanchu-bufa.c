// chanchu_bufa.c ��ܲ���
inherit SKILL;
string *dodge_msg = ({
    "ֻ��$nһ�С�"+RED+"�ɾ���"+NOR+"�����������ϱ�ֱ���������࣬�����$N��һ�С�\n",
    "����$nһ��ʹ����"+WHT+"��������"+NOR+"��������Ʈ��������һ�ݣ����ѱܿ���\n",
     "$nһ�С�"+CYN+"���뵾��"+NOR+"������������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
    "����$nһ����"+YEL+"����˳�"+NOR+"��������һ�ã�$N��һ�����˸��ա�\n",
    "ȴ��$n��"+RED+"󸷭�׶�"+NOR+"�����㲻��أ����Դܿ����ߣ����˿�ȥ��\n",
    "$n����һ�С�"+GRN+"������"+NOR+"��������΢�Σ��о����յرܿ���$N��һ�С�\n"
});
int valid_enable(string usage) { return (usage == "dodge");  }
int valid_learn(object me)
{
    if (me->query_skill("dodge",1) <= me->query_skill("chanchu-bufa",1) )
        return notify_fail("��Ļ����Ṧ�����������޷������������ܲ�����\n");
    else    return 1;
}
int practice_level(){   return 60;  }
string query_dodge_msg(string limb,object me)
{
    me->set_temp("apply/dodge",me->query_skill("chanchu-bufa")/3);
    return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
    if( (int)me->query("qi") < 45 )
        return notify_fail("�������̫���ˣ���������ܲ�����\n");
    me->receive_damage("qi", 35);
    return 1;
}
