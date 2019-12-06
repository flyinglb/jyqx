// kuihua-xinfa (protect)
#include <ansi.h>
void remove_effect(object me, int amount);
int exert(object me, object target)
{
    int skill;
    if( target != me ) 
        return notify_fail("�����ķ�ֻ�ܶ��Լ�ʹ�á�\n");
    if( (int)me->query("neili") < 1000  ) 
        return notify_fail("�������������\n");
    if ((int)me->query_temp("apply/shade_vision"))
        return notify_fail("���Ѿ����˹����ˡ�\n");
    skill = me->query_skill("kuihua-xinfa",1);
        if (skill<90) return notify_fail("��Ŀ����ķ���������졣\n");
    message_vision( HIW "$N΢һ������������ķ�����������ͬ����������һ�㣬Ư��������\n"
    "����������\n" NOR, me);
    me->add("neili",-300);
    me->set_temp("apply/shade_vision",1);
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill/2);
    if( me->is_fighting() ) me->start_busy(1);
    return 1;
}
void remove_effect(object me, int amount)
{
    if (!me)    return;
    me->delete_temp("apply/shade_vision");
    message_vision( BOLD "$N�Ŀ����ķ�������ϣ�ȫ�����һ�٣��ֳ��������Ρ�\n" NOR, me);
}
void reset() { }
int clean_up() { return 1; }

