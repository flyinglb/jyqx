
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    int skill;
    if( !target ) target = offensive_target(me);
    if( !target
    ||  !target->is_character()
    ||  !me->is_fighting(target) )
        return notify_fail("���ɷ�ֻ����ս����ʹ�á�\n");
    if( (int)me->query_skill("shedao-qigong", 1) < 60 )
        return notify_fail("����ߵ��湦������죬����ʹ�ó��ɷ���\n");
    if( (int)me->query("neili") < 300 )
        return notify_fail("���Ѿ����þ�ƣ����,���������ˡ�\n");
    if( (int)me->query_temp("chang") == 50 )
        return notify_fail("���Ѿ�����̫����,�����ٳ��ˡ�\n");
    skill = me->query_skill("force");
    me->add("neili", -200);
    message_vision(
        HIR "ֻ��$N���������дʣ����֮���书�����\n" NOR, me);
    me->add_temp("apply/attack", 1);
    me->add_temp("apply/dodge", 1);
    me->add_temp("apply/defense", 1);
    me->add_temp("chang", 1);
    return 1;
}
