// powerup.c ������������
#include <ansi.h>
void remove_effect(object me, int amount);
int exert(object me, object target)
{
    int skill;
    if( target != me ) 
        return notify_fail("��ֻ���û��������������Լ���ս������\n");
    if( (int)me->query("neili") < 100  ) 
        return notify_fail("�������������\n");
    if( (int)me->query_temp("powerup") ) 
        return notify_fail("���Ѿ����˹����ˡ�\n");
    skill = me->query_skill("huntian-qigong",1);
        if (skill<60) return notify_fail("��Ļ���������������졣\n");
    me->add("neili", -100);
    me->receive_damage("qi", 0);
    message_vision(
    HIR "$N΢һ�����������������ȫ��ǽڷ���һ�󱬶�������졣\n" NOR, me);
    me->add_temp("apply/attack", skill/3);
    me->add_temp("apply/dodge", skill/3);
    me->set_temp("powerup", 1);
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill/2);
    if( me->is_fighting() ) me->start_busy(3);
    return 1;
}
void remove_effect(object me, int amount)
{
  if (!me) return;
   if ( (int)me->query_temp("powerup") ) {
    me->add_temp("apply/attack", - amount);
    me->add_temp("apply/dodge", - amount);
    me->delete_temp("powerup");
    tell_object(me, "��Ļ�������������ϣ��������ջص��\n");}
}
int clean_up()
{
    return 1;
}
void reset()
{
}
