// lingboweibu.c �貨΢��
#include <ansi.h>
inherit SKILL;
string *dodge_msg = ({
        "ֻ��$nʩչ�貨΢���������ϣ�է��է�������޳��򣬽�ֹ���ڡ�\n",
        "ֻ��$nʩչ�貨΢����������ӯ���·�����֮���£���֪���ľ͵�������֮�⡣\n",
        "$n����ӰƮƮ��������֮��ѩ��ʩչ�������貨΢����$N��$n���½Ƕ�մ������\n",
        "����$nʩչ�貨΢������һת����һб�����Ѿ��Ƶ���$N�����ᡣ\n",
        "����$nʩչ�貨΢����ֻ�����赭д������̤��һ����������رܿ���$N�Ĺ��ơ�\n",
        "ֻ��$n��Ӱ�������һת����Ѹ����Ʈ������ʩչ�������貨΢����\n",
        "$Nֻ������ǰһ����ͷ�Է��裬ֻ�������涼��$n����Ӱ��\n",
        "$n��������̤��һ����ʩչ�貨΢����������������$Nǣ��������ת��\n",
});
int valid_enable(string usage) 
{ 
    return (usage == "dodge"); 
}
int practice_level(){   return 101;  }
int valid_learn(object me)
{
        if( (int)me->query("max_neili") < 500 )
                return notify_fail("���������Ϊ�������޷���ϰ����Ĳ�����\n");
        if( (int)me->query_skill("force") < 80 )
                return notify_fail("����ڹ���򲻹����޷���ϰ����Ĳ�����\n");
    if (me->query_skill("dodge", 1) <=me->query_skill("lingboweibu", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
string query_dodge_msg(string limb,object me)
{
        me->set_temp("fight/dodge",me->query_skill("shaolin-shenfa",1)/3);
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("�������̫���ˣ��������貨΢����\n");
        me->receive_damage("qi", 30);
        if (me->query("neili")<1*me->query("max_neili"))
        me->add("neili",me->query_skill("dodge")/30);
        else
        return notify_fail(YEL"��ֻ�����ؿ������ޱȣ�����������������\n"NOR);
        return 1;
 }
string perform_action_file(string action)
{
    return __DIR__"lingboweibu/" + action;
}

