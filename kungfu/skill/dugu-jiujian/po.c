// po.c ���ܾ�ʽ��
#include <ansi.h>
inherit F_SSERVER;
int perform(object me)
{
    string msg;
    object weapon;
    int skill, jing_cost;
//    mapping my_fam  = me->query("family");
    skill = me->query_skill("dugu-jiujian",1);
    if (me->query_int()<50)
        jing_cost = (int)me->query_int() - 50;
    else    jing_cost=1;
    if( me->is_fighting() )
        return notify_fail("���ܾ�ʽ��������ս����������\n");
 
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("�������ȥ��һ�ѽ���\n");
    if( !skill || (skill < 60))
        return notify_fail("��Ķ��¾Ž��ȼ�����, �����������ܾ�ʽ����\n");
    if( me->query("neili") < 50 )
        return notify_fail("�������������û�������������ܾ�ʽ����\n");
    if (me->query_skill("sword",1)<= skill)
        return notify_fail("��Ļ��������������޷�ͨ���������ܾ�ʽ����߶��¾Ž��ļ��ɣ�\n");
    if( me->query("jing") < -jing_cost )
        return notify_fail("������̫���ˣ��޷����о����������ܾ�ʽ����\n");
    msg = HIC "$Nʹ�����¾Ž�֮���ܾ�ʽ����������" + weapon->name() + HIC "���������̡�\n" + NOR;
    message_vision(msg, me);
    me->add("neili", -50);
    me->add("jing", jing_cost);
    if ( skill < 60)
        me->improve_skill("dugu-jiujian", 10);
    else if (skill < 90)
        me->improve_skill("dugu-jiujian", 10 + random((int)me->query_int() - 9));
    else if (skill < 140)
        me->improve_skill("dugu-jiujian", 10 + random((int)me->query_int() * 2 - 9));
    else if (skill < 200)
        me->improve_skill("dugu-jiujian", 10 + random((int)me->query_int() * 4 - 9));
    else
        me->improve_skill("dugu-jiujian", 10 + random((int)me->query_int() * 8 - 9));
    msg = MAG"$P�ġ����¾Ž��������ˣ�\n"NOR;
	if (random(10)>8)    me->start_busy(1);
    message_vision(msg, me);
    return 1;
}
