// buddhism-force (protect)
#include <ansi.h>
void remove_effect(object me, int amount);
int exert(object me, object target)
{
    int skill;
    if( target != me ) 
        return notify_fail("��ղ����񹦻�������ֻ�ܶ��Լ�ʹ�á�\n");
    if( (int)me->query("neili") < 1000  ) 
        return notify_fail("�������������\n");
    if( (int)me->query_temp("protect") ) 
        return notify_fail("���Ѿ����˹����ˡ�\n");
    skill = me->query_skill("buddhism-force",1);
        if (skill<90) return notify_fail("��Ľ�ղ����񹦻�������졣\n");
    me->receive_damage("qi", 0);
    message_vision( HIW "$N΢һ���������ղ��������񹦣�ȫ������һ��\n" NOR, me);
    me->add_temp("apply/armor_vs_force",skill); 
    me->set_temp("protect", 1);
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill/2);
    if( me->is_fighting() ) me->start_busy(1);
    return 1;
}
void remove_effect(object me, int amount)
{
    if (!me)    return;
    me->add_temp("apply/armor_vs_force", - amount);
    me->delete_temp("protect");
    tell_object(me, BOLD"��Ľ�ղ���������������ϣ��������ջص��\n"NOR);
}
void reset() { }
int clean_up() { return 1; }
