// chan.c ��糾�� ���־�
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target
    ||  !target->is_character()
    ||  !me->is_fighting(target) )
        return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if( target->is_busy() )
        return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");
    msg = CYN "$Nʹ����糾���������־�������������ͼ��$n��ȫ���ס��\n";
    me->start_busy(random(1));
    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
        msg += "���$p��$P���˸����ֲ�����\n" NOR;
        target->start_busy( (int)me->query_skill("qiufeng-chenfa") / 20 + 2);
    } else {
        msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
        me->start_busy(4);
    }
    message_vision(msg, me, target);
    return 1;
}
