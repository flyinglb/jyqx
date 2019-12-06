// powerup.c
#include <ansi.h>
void remove_effect(object me, int amount);
int exert(object me, object target)
{
    int skill;
    if( target != me ) return notify_fail("��ֻ���������޼������Լ���ս������\n");
    if( (int)me->query("neili") < 100 ) return notify_fail("�������������\n");
        if( (int)me->query_temp("powerup") ) return notify_fail("���Ѿ����˹����ˡ�\n");
    skill = me->query_skill("xuantian-force",1);
        if (skill<60) return notify_fail("��������޼���������졣\n");
    me->add("force", -100);
        me->receive_damage("qi", 0);
    message_vision(
        HIR "$N����һ���������������޼��ѽ�ȫ��Ǳ����������\n" NOR, me);
    me->add_temp("apply/attack", skill/2);
    me->add_temp("apply/dodge", skill/2);
    me->set_temp("powerup", 1);
    me->add("bellicosity",skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/2 :), skill/2);
    if( me->is_fighting() ) me->start_busy(3);
    return 1;
}
void remove_effect(object me, int amount)
{
     if (!me)   return;
    me->add_temp("apply/attack", - amount);
    me->add_temp("apply/dodge", - amount);
    me->delete_temp("powerup");
    tell_object(me, "��������޼�������ϣ��������ջص��\n");}
int clean_up()
{
    return 1;
}
void reset()
{
}

