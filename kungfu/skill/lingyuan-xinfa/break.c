// break -�������Ƹ֡�
// made by deaner
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int exert(object me, object target)
{
    string msg;
    object target_w;
    target_w = target->query_temp("weapon");

    if( !target )
    return notify_fail("��ʽ��exert break [Ŀ��]\n");
    if( !target
    ||      !target->is_character()
    ||      !me->is_fighting(target) )
   return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á������Ƹ֡���\n");

    if( target->is_busy() )
   return notify_fail(target->name() + "Ŀǰ���ڷ�㶣��ǽ����ĺ�ʱ��!\n");
    if( (int)me->query_skill("lingyuan-xinfa", 1) < 50 )
    return notify_fail("�����Ԫ�ķ���򲻹���������ʹ�á������Ƹ֡���\n");

    msg = HIC "$N���绬�����Ե���������һ������֮��˳��Ѫ�����紫��˫���͹�Ѩ�� 
�����������֮���ͼ������������$n���еı��У�\n";
    me->start_busy(2);

    if (target->query_temp("weapon") ||
   target->query_temp("secondary_weapon")) {

    if( random(me->query("combat_exp")) >
   (int)target->query("combat_exp")/3 ) {
    msg += HIW"���$p���е�"+target_w->query("name")+"���������֮��һ������
���˸����飡\n" NOR;
    target_w->unequip();
    target_w->move(environment(target));
    target_w->set("name", "�����" + target_w->query("name"));
    target_w->set("value", target_w->query("value")/10);
    target_w->set("weapon_prop", 0);
    target->reset_action();
    target->start_busy( (int)me->query_skill("lingyuan-xinfa") / 20 );
    } else {
    msg += "����$p�������У����˿�ȥ��$P�ļ�ıû�еóѡ�\n" NOR;
    }
    message_vision(msg, me, target);
    return 1;
    }
    return notify_fail(target->name() + "Ŀǰ�ǿ��֣�ûʲô��������ġ�\n");
}
