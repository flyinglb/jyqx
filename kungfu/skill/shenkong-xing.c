//
// shenkong-xing.c �����
//
inherit SKILL;
string *dodge_msg = ({
"$nʹ��һ�С�"+HIW+"�Ŀ�"+NOR+"������������Ʈȥ \n",
"$nʹ��һ�С�"+HIG+"���Կ�"+NOR+"����˫��һ�㣬Ծ������֮�� \n",
"$nʹ��һ�С�"+HIY+"����"+NOR+"��������һ�䣬����$N��� \n",
"$n���һ����ʹ��һ�С�"+HIM+"�󰲿�"+NOR+"������$Nͷ��Խ�� \n",
"$nʹ��һ�С�"+HIB+"���"+NOR+"����������Ʈȥ��˲��������$N��ǰ \n",
"$nʹ��һ�С�"+HIC+"��տ�"+NOR+"������ʱ$N��Χ����$n����Ӱ \n",
});
int practice_level(){   return 60;  }
int valid_enable(string usage)
{
    return usage == "dodge";
}
int valid_learn(object me)
{
    if (me->query_skill("dodge", 1) <=me->query_skill("shenkong-xing", 1))
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
        return notify_fail("�������̫���ˣ�������ϰ����С�\n");
    me->receive_damage("qi", 20);
    return 1;
}
