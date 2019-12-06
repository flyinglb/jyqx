#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    object weapon;
    int damage;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target||!target->is_character()||!me->is_fighting(target) )
    return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á����ʽ����\n");
    if( (int)me->query_skill("hujia-dao",1) < 100)
    return notify_fail("��Ŀǰ������ʹ���������ʽ����\n");
    if( (int)me->query("neili") < 400 )
    return notify_fail("�����������ʹ�������ʽ����\n");
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
    return notify_fail("�����ʽ���������ŵ�����ʹ����\n");
    me->add("neili", -60);
    msg = HIC"$N��ȻһЦ�����Ϳ�ݾ��׵ĵ�����Ȼ��ø���������������һ˲֮�䣬\n\n"+
    "$N������ʮ��������\n\n"+
    "�������ŷ磬���ﺬ�ŵ�Ӱ��$nֻ����������ֹͣ�ˣ�\n\n"NOR;
    me->start_busy(2);

    if( random(me->query("combat_exp")) >
      (int)target->query("combat_exp")/3 ) {
    target->start_busy( (int)me->query_skill("hujia-dao") / 20 );
    damage = (int)me->query_skill("hujia-dao", 1)+(int)me->query_skill("blade", 1)/2;
    damage = damage + random(damage);

    target->receive_damage("qi", damage);
    target->receive_wound("qi", damage/2);
    target->receive_damage("jing", damage/2);
    target->receive_wound("jing", damage/3);
   msg += HIR
"ֻ��$n�ѱ�$N�е����������Ѫ�������ȫ�����������\n"NOR;
    } else {
    msg += HIC "����$p��æ����㿪��$P����û�еóѡ�\n" NOR;
    }
    message_vision(msg, me, target);
    if(userp(target)) target->fight_ob(me);
    else if( !target->is_killing(me) ) target->kill_ob(me);

    return 1;
}

