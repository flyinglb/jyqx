// chan.c ���±޷������ơ���
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
    if( (int)me->query_skill("riyue-bian",1) < 50)
        return notify_fail("��ġ����±޷�����ûѧ���ң��ò��ˡ������־���\n");
  if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("skill_type") != "whip")
            return notify_fail("��ʹ�õ��������ԡ�\n");
    if( target->is_busy() )
        return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");
    msg = CYN "$Nʹ�����±޷������ơ���������������ͼ��$n��ȫ�����������\n";
    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/5 ) {
        msg += "���$p��$P���˸����ֲ�����\n" NOR;
        target->start_busy( (int)me->query_skill("riyue-bian",1) / 20 + 2);
        me->start_busy(2);
    } else {
        msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
        me->start_busy(4);
    }
    message_vision(msg, me, target);
    return 1;
}
