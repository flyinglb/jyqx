// jiao.c ���µ������¡��־�
// jacki��1997.7.25

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    string msg;
    object my_w,target_w;
    my_w = me->query_temp("weapon");
    target_w = target->query_temp("weapon");

    if( !target ) target = offensive_target(me);

    if( !target
    ||      !target->is_character()
    ||      !me->is_fighting(target) )
   return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á����־�����\n");

    if( target->is_busy() )
   return notify_fail(target->name() + "Ŀǰ��ƣ���мܣ��ӽ������ɢ�\n");

    if( (int)me->query_skill("wuyue-blade", 1) < 50 )
   return notify_fail("������µ���������죬����ʹ�á��¡��־���\n");

    msg = CYN "$N���һ����չ�����µ������¡��־�����������������ͼ����$n�ı��С�\n";
    me->start_busy(2);

    if (target->query_temp("weapon") ||
   target->query_temp("secondary_weapon")) {

    if( random(me->query("combat_exp")) >
   (int)target->query("combat_exp")/2 ) {
    if( target_w->weight() > 2 * random(my_w->weight()) ) {
   msg += "���$p���е�$w��$Pǿ��һ�£���Ҳ���ղ�ס���������ַɳ���\n" NOR;
    target_w->unequip();
    target_w->move(environment(target));
    target->reset_action();
   target->start_busy( (int)me->query_skill("wuyue-blade") / 20 );
}
   msg += "���$p���еı��б�$P��ǿ��һ�����˸����飡\n" NOR;
    target_w->unequip();
    target_w->move(environment(target));
    target_w->set("name", target_w->query("name") + "����Ƭ");
    target_w->set("value", 0);
    target_w->set("weapon_prop", 0);
    target->reset_action();
   target->start_busy( (int)me->query_skill("wuyue-blade") / 20 );
    } else {
   msg += "����$pͨ��������мܣ���û����$P�ļ�ı�óѡ�\n" NOR;
    }
    message_vision(msg, me, target);
    return 1;
    }
    return notify_fail(target->name() + "Ŀǰ�ǿ��֣������ʲô��\n");
}

