// anying.c
inherit SKILL;
#include <ansi.h>
string *dodge_msg = ({
     "$nһ����"+HIW+"��������ͷ"+NOR+"��������$N�Ĺ���Ʈ�𣬴��ݶ����һ�С�\n",
     "$nʹ��һ�С�"+HIR+"��Į����ֱ"+NOR+"������Ȼ�������࣬���$N���˸��ա�\n",
    "$n����һҡ���ó�������Ӱ��һ�С�"+HIY+"��Ӱ��б��"+NOR+"�������$N�Ĺ��ơ�\n",
    "$nһ�С�"+HIG+"��������ˮ"+NOR+"������Ծ��ٿ��������$N���\n",
    "$n��һҡ����һ�Σ�һ�С�"+HIC+"���֪��"+NOR+"��������������\n",
     "$n˫��һ�㣬бб����ʹ����"+MAG+"б���ӻ���"+NOR+"��������$N��ࡣ\n",
});
int valid_enable(string usage) 
{ 
    return (usage == "dodge") ;
}
int practice_level(){   return 60;  }
int valid_learn(object me) { 
    if (me->query_skill("dodge",1)<=me->query_skill("anying-fuxiang",1))
        return notify_fail("��Ļ����Ṧ�����������޷���������ļ��ɡ�\n");
    else
        return 1;
    
}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
        if( (int)me->query("qi") < 30 )
            return notify_fail("�������̫���ˣ���������Ӱ���㡣\n");
        if (me->query_skill("yan-shuangfei", 1) < 30)
            me->receive_damage("qi", 10);
        me->receive_damage("qi", 20);
        return 1;
}
