// ren.c  ���ǽ��������ͬ�ʡ�

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
        return notify_fail(RED"��ʲô��Ц��ûװ��������ʹ�����ͬ�ʡ���\n"NOR);
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("�����ͬ�ʡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if ((int)me->query_skill("liangyi-jian", 1) < 60 )
        return notify_fail(WHT"�����ǽ���������죬ʹ���������ͬ�ʡ���\n"NOR);
    if ((int)me->query_skill("taiji-shengong", 1) < 90 )
        return notify_fail(RED"��̫���񹦻�򲻹���ʹ���������ͬ�ʡ���\n"NOR);
    if ((int)me->query("max_neili")<400)
        return notify_fail(RED"��������Ϊ���㣬�޷�����������\n"NOR);
    if ((int)me->query("neili")<200)
    {
        return notify_fail(HIC"����������������û�ܽ������ͬ�ʡ�ʹ�꣡\n"NOR);
    }
    msg = HIC "$N���г�����âԾ�������Ⱪ������������ƺ������Ҵ���$n��\n"NOR;
    msg += HIC"$n��������ƫ�󣬼�������ת����ֻ��һɲ������ɲʱϮ�����ף�\n"NOR;
    if (random(me->query_skill("force")) > target->query_skill("force")/2|| 
       random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
    {
        me->start_busy(2);
        target->start_busy(random(3));
        damage = (int)me->query_skill("liangyi-jian", 1) + (int)me->query_skill("sword", 1)/2;
        damage = damage/2 + random(damage);
        target->receive_damage("qi", damage/2);
        target->receive_wound("qi", damage/3);
    msg += HIC"$n��æ��ת��ȴ����$N�Ľ�����û����ƫ��һʽ�����ͬ�ʡ���\n"NOR;
    msg += HIC"$n��������һ��Ѫ����$nһ��ͷ�������ؿ���ѪӿȪ�����\n"NOR;
        me->add("neili", -damage/5);
    } else
    {
        me->start_busy(2);
    msg += HIY"����$p����һЦ��������ת����Ȼ$P�Ľ�ʽͻȻ��չ����$p��ǰ\n"NOR;
    msg += HIY"�����������硣һ����ë��û�˵���\n"NOR;
    }
    message_vision(msg, me, target);
    if(!target->is_fighting(me)) target->fight_ob(me);
//    if(userp(target)) target->fight_ob(me);
//    else if( !target->is_killing(me) ) target->kill_ob(me);
    return 1;
}
