
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    if( !target ) target = offensive_target(me);
    if( !target
    ||  !target->is_character()
    ||  !me->is_fighting(target) )
        return notify_fail("���ɷ�ֻ����ս����ʹ�á�\n");
    if( (int)me->query_skill("shedao-qigong", 1) < 80 )
        return notify_fail("����ߵ��湦������죬����ʹ�ó��ɷ���\n");
    if((int)me->query_temp("apply/attack")<=0||(int)me->query_temp("apply/dodge") <=0||(int)me->query_temp("apply/defense") <=0 )
        return notify_fail("��Ŀǰս����̫��,�����ٻָ������ˡ�\n");
    if( (int)me->query_temp("chang") <= 30  )
        return notify_fail("���Ѿ�����̫����,�����ٳ��ˡ�\n");
    message_vision(HIR "ֻ��$N���������дʣ����֮���������ǣ�\n" NOR, me);
    me->add_temp("apply/attack", -1);
    me->add_temp("apply/dodge", -1);
    me->add_temp("apply/defense", -1);
    me->add_temp("chang", 1);
    me->add("neili", 100);
    return 1;
}
