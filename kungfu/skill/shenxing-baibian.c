// shenxing-baibian.c ���аٱ�
inherit SKILL;
string *dodge_msg = ({
"$nһʽ��"+BLK+"������ˮ"+NOR+"�������㣬�Ų��ƣ�������������ˮ��ֱ�������ࡣ\n",
"$nһʽ��"+HIR+"Ǳ��ҹ��"+NOR+"������Ȼһ������ȫ�����ض��У���ʱ������$N���������ơ�\n",
"$nһʽ��"+YEL+"�Ʋ�����"+NOR+"�����㲻�����ֲ�̧��һת�ۼ���Ƶ���$N�����\n",
"$nһʽ��"+BLU+"����Ӱ"+NOR+"����һת��䣬����˷�Ʈ����������$n����Ӱ����$N�����޴롣\n",
"$nһʽ��"+BOLD+"��תǬ��"+NOR+"������̤�㣬��תǬ������һ�Σ��㵽����Զ�ĵط���\n",
"$nһʽ��"+WHT+"���ϲ�¥"+NOR+"�������ڿ��У������������һ�㣬��$Nͷ���ڿն�����\n",
"$nһʽ��"+RED+"���ӳ�ˮ"+NOR+"��������һ����ȫ��Ϊһ����Ӱ�����ĵش�$Nͷ��Ʈ�䡣\n",
"$nһʽ��"+HIB+"���·ת"+NOR+"�������������ݰ㼱ת����ʱһ������ӿ������$N���Զ�����\n",
"$nһʽ��"+YEL+"�����ﲨ"+NOR+"��������ٿ�Ĵ�$N����ǰֱ�Ƶ����$N�ɴ������ۣ��������ԡ�\n",
"$nһʽ��"+HIB+"���ӻ�ͷ"+NOR+"��������ٿ�Ĵ�$N����ǰƮ��������һ˦������֮����\n",
});
int practice_level(){   return 100;  }
int valid_enable(string usage)
{
    return usage == "dodge";
}
int valid_learn(object me)
{
    if (me->query_skill("dodge", 1) <=me->query_skill("shenxing-baibian", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
string query_dodge_msg(string limb,object me)
{
        me->set_temp("fight/dodge",me->query_skill("shenlong-baibian",1));
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    if( (int)me->query("qi") < 40 )
        return notify_fail("�������̫���ˣ����������аٱ䡣\n");
    me->receive_damage("qi", 20);
    return 1;
}
