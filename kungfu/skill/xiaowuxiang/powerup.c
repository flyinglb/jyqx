#include <ansi.h>
void remove_effect(object me, int amount);
int exert(object me, object target)
{
    int skill;
    if( target != me )
        return notify_fail("��ֻ����С���๦�������Լ���ս������\n");
    if( (int)me->query("neili") < 100  )
        return notify_fail("�������������\n");
    if( (int)me->query_temp("powerup") )
        return notify_fail("���Ѿ����˹����ˡ�\n");
    skill = me->query_skill("xiaowuxiang",1);
    if (skill<50) return notify_fail("���С���๦��������졣\n");
    me->add("neili", -50);
    me->receive_damage("qi", 0);
    message_vision(
    HIW "$N΢һ����������Ϣ������С���๦����ȫ��Ǳ���������ޡ�\n" NOR, me);
    me->add_temp("apply/attack", skill/3);
    me->add_temp("apply/dodge", skill/3);
    me->set_temp("powerup", 1);
    me->add("bellicosity",skill);
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill/2);
    if( me->is_fighting() ) me->start_busy(3);
    return 1;
}
void remove_effect(object me, int amount)
{
   if ( (int)me->query_temp("powerup") ) {
    me->add_temp("apply/attack", - amount);
    me->add_temp("apply/dodge", - amount);
    me->delete_temp("powerup");
    tell_object(me, "���С���๦������ϣ��������ջص��\n");}
}
int clean_up()
{
    return 1;
}
void reset()
{
}

