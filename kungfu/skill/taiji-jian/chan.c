// chan.c ̫�������������־�
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    object weapon;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target
    ||  !target->is_character()
    ||  !me->is_fighting(target) )
        return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("��ʹ�õ��������ԡ�\n");
    if( target->is_busy() )
        return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");
        
    if( (int)me->query_skill("taiji-jian", 1) < 40 )
        return notify_fail("���̫������������죬����ʹ�á������־���\n");
    if (!me->visible(target))    return notify_fail("�㿴����"+target->name()+"��\n");
    msg = HIG "$Nʹ��̫�������������־�����������������ͼ����$n�Ĺ��ơ�\n";
    me->start_busy(1);
    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
        msg += HIR " ���$p��$P���˸����ֲ�����\n" NOR;
        target->start_busy( (int)me->query_skill("taiji-jian") / 20 );
    } else {
        msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
        me->start_busy(2);
    }
    message_vision(msg, me, target);
    return 1;
}
