// bashi-shentong.c ��ʶ��ͨ
// Modified by Venus Oct.1997

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage=="magic"; }

int valid_learn(object me)
{
    if( (int)me->query_skill("buddhism",1) < 10
    ||(int)me->query_skill("buddhism",1) <= (int)me->query_skill("bashi-shentong",1) )
    return notify_fail("��ķ���Ϊ����������޷�ѧϰ��ʶ��ͨ��\n");
    return 1;
}

string conjure_magic_file(string spell)
{
    return __DIR__ + "bashi-shentong/" + spell;
}

int practice_skill(object me)
{

    if( (int)me->query("jingli") < 10)
    return notify_fail("��ľ���������\n");

    if( (int)me->query("jing") < 35 )
   return notify_fail("��ľ����޷����С�\n");

    me->add("jingli", -5);
    me->receive_damage("jing", 30);

    message_vision(HIY"$N��Ŀ��������̫�飬��ʼ��ϰ��ʶ��ͨ����\n"NOR,me);
    if( random((int)me->query("jing")) < 10)
    {
    tell_object(me,HIC"ͻȻ��һ��������������Ԫ������ͷ���ۡ��ۡ��ۣ�\n"NOR);
    tell_room(environment(me),HIY"����к�Ȼ��ಡ���������һ�����£��ֺ���ʲ
ô��û�У�ȴ��"+me->query("name")+"��ʼ���°�ĭ�ˡ� \n"NOR,me);
    me->unconcious();
    return 0;
    }
    else return 1;
}

