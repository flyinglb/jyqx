// shendao.c  Ѫ������Ѫ�񵶡�

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    object weapon;

    if (!target ) target = offensive_target(me);
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
        return notify_fail(RED"װ��������ʹ�á���Ѫ�񵶡���\n"NOR);
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("����Ѫ�񵶡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if ((int)me->query_skill("xue-dao", 1) < 100 )
        return notify_fail(WHT"��Ѫ������������죬ʹ��������Ѫ�񵶡���\n"NOR);
    if ((int)me->query_skill("longxiang", 1) < 60 )
        return notify_fail(RED"�������������򲻹���ʹ��������Ѫ�񵶡���\n"NOR);
    if ((int)me->query("max_neili") < 600)
        return notify_fail(RED"��������Ϊ���㣬�޷�����������\n"NOR);
    if ((int)me->query("neili") < 600)
    {
        return notify_fail(HIC"����������������û�ܽ�����Ѫ�񵶡�ʹ�꣡\n"NOR);
    }
    msg = HIC "$N���ֳֵ������һ�գ�һ��Ѫ�齦�����棬�������ұ��ճ���һƬѪ��
��ס��Ӱ��$n��ͷ���䣬\n"NOR;
    if ( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
    {
        damage = random((int)(me->query("shen")/-1000))+(int)(me->query("shen")/-3000);
        me->add("neili", -600);
        me->receive_wound("qi", me->query("qi")/10);
        me->start_busy(random(3));
        target->start_busy(random(3));
        target->receive_damage("qi", damage);
        target->receive_wound("qi", damage/2);
msg += HIC"$n��æ������ã���Ѫ��������ֻ����ǰһ��Ѫ�죬����������£���Ѫ��
���������󺿣�\n"NOR;
    } else
    {
        me->start_busy(2);
        me->receive_wound("qi", me->query("qi")/20);
msg += HIY"����$n������ã����Ĳ�æ�������$N��Ѫ����\n"NOR;
        me->add("neili", -200);
    }
    message_vision(msg, me, target);
    if(!target->is_fighting(me)) target->fight_ob(me);
    return 1;
}
