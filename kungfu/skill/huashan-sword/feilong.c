// feilong.c  ��ɽ���������������

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    object weapon;

    if (!target ) target = offensive_target(me);
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"װ��������ʹ�á������������\n"NOR);
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("�����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if ((int)me->query_skill("huashan-sword", 1) < 150 )
        return notify_fail(WHT"�㻪ɽ����������죬ʹ�����������������\n"NOR);
//    if ((int)me->query_skill("huashan-neigong", 1) < 100 )
//        return notify_fail(RED"�㻪ɽ�ڹ���򲻹���ʹ�����������������\n"NOR);
    if ((int)me->query_skill("zixia-shengong", 1) < 100 )
        return notify_fail(RED"����ϼ�񹦻�򲻹���ʹ�����������������\n"NOR);
    if ((int)me->query("max_neili") < 600)
        return notify_fail(RED"��������Ϊ���㣬�޷�����������\n"NOR);
    if ((int)me->query("neili") < 400)
    {
        return notify_fail(HIC"����������������û�ܽ������������ʹ�꣡\n"NOR);
    }
    msg = HIC "$N���������һ�������������̽����˾��ڱۣ�����һ����$n���˳�ȥ��\n"NOR;
    if ( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
    {
        me->start_busy(2);
        target->start_busy(random(3));
        damage = target->query("qi");
        target->receive_damage("qi", damage-10);
        target->receive_wound("qi", damage/2);
msg += HIC"$n��æԾ�𣬵����������ֻ��һ���ʹ������������������Ѫ�ɽ���Ƥ�����\n"NOR;
        me->set("neili", 100);
    } else
    {
        me->start_busy(2);
msg += HIY"����$n����һЦ��������ָ��������$N�Ľ����ϣ���б����ء�\n"NOR;
        me->add("neili", -200);
    }
    weapon->move(environment(me));
    message_vision(msg, me, target);
    if(!target->is_fighting(me)) target->fight_ob(me);
    return 1;
}
