// muyeyingyang.c ��Ұӥ��
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if((int)me->query_str() < 30)
        return notify_fail("���������,����ʹ����Ұӥ�\n");
    if((int)me->query_skill("sougu",1) < 150)
        return notify_fail("����ѹ�ӥצ����Ϊ����,Ŀǰ������ʹ����Ұӥ�\n");
    if((int)me->query("neili") < 800)
        return notify_fail("���������ڲ���, ����ʹ����Ұӥ�\n");
    if( target->is_busy() )
        return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");
    msg = HIY "$Nʹ���ѹ�ӥצ����������Ұӥ���˫צ���ץ��$n��ȫ��ҪѨ��\n";
    if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 2 ) {
        msg += "���$p��$P���˸����ֲ�������ʱ�������ã�\n" NOR;
        target->start_busy( (int)me->query_skill("sougu",1) / 10 + 2);
        me->add("neili", -150);
        me->start_busy(2);
    } else {
        msg += HIG "����$p������$P����ͼ����û���ϵ���\n" NOR;
        me->start_busy(4);
    }
    message_vision(msg, me, target);
    return 1;
}
