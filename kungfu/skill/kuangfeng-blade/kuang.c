//kuang.c -������ʮһʽ��
// Modified by Venus Oct.1997
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target||!target->is_character()||!me->is_fighting(target) )
    return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á�����ʮһʽ����\n");
    if( (int)me->query_skill("kuangfeng-blade",1) < 70)
    return notify_fail("��Ŀǰ������ʹ����������ʮһʽ����\n");
    if( (int)me->query("neili") < 200 )
    return notify_fail("�������������\n");
    me->add("neili", -60);
    msg = HIC"$N��ȻһЦ�����Ϳ�ݾ��׵ĵ�����Ȼ��ø���������������һ˲֮�䣬"+
    "$N��������ʮһ�����������ŷ磬���ﺬ�ŵ�Ӱ��$nֻ����������ֹͣ�ˣ�\n"NOR;
    me->start_busy(2);

    if( random(me->query("combat_exp")) >
      (int)target->query("combat_exp")/3 ) {
    target->start_busy( (int)me->query_skill("kuangfeng-blade") / 20 );
    damage = (int)me->query_skill("kuangfeng-blade", 1)+(int)me->query_skill("blade", 1)/2;
    damage = damage + random(damage);

    target->receive_damage("qi", damage);
    target->receive_wound("qi", damage/2);
   msg += RED
"ֻ��$n�ѱ�$N�е����������Ѫ�������ȫ�����������\n"NOR;
    } else {
    msg += HIC "����$p��æ����㿪��$P����û�еóѡ�\n" NOR;
    }
    message_vision(msg, me, target);
    if(userp(target)) target->fight_ob(me);
    else if( !target->is_killing(me) ) target->kill_ob(me);

    return 1;
}

