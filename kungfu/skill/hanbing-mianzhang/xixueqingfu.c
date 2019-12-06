// xixueqingfu.c ��Ѫ����
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
    string msg;
    object weapon, target;
    int skill, ap, dp, neili_wound, qi_wound;
    me->clean_up_enemy();
    target = me->select_opponent();
    skill = me->query_skill("hanbing-mianzhang",1);
    if( !(me->is_fighting() ))
        return notify_fail("����Ѫ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
    if (objectp(weapon = me->query_temp("weapon")))
        return notify_fail("��ʹ����������\n");
    if( skill < 60)
        return notify_fail("��ġ��������ơ��ȼ�����, ����ʹ�á�ǧ����⡹��\n");
    if( me->query_skill("dodge",1) < 150 )
        return notify_fail("����Ṧ�������޷����á���Ѫ���𡹣�\n");
 
    msg = HIC "$NͻȻ��ͬ����Ѫ���𡹣��۽�$n����ǰ���������$n���ʺ�ҧȥ��\n"NOR;
    message_vision(msg, me, target);
 
    ap = me->query("combat_exp") + skill * 400;
    dp = target->query("combat_exp") / 2;
    if( dp < 1 )
        dp = 1;
    if( random(ap) > dp )
    {
        if(userp(me))
            me->add("neili",-100);
        msg = HIG "$nֻ�����ʺ�һ���ʹ��$N���ڿ���$n����Ѫ��\n"NOR;
        neili_wound = 100 + random(skill);
        if(neili_wound > target->query("neili"))
            neili_wound = target->query("neili");
        qi_wound = neili_wound / 5;
        if(qi_wound > target->query("qi"))
            qi_wound = target->query("qi");
        target->add("neili", -neili_wound);
        target->add("qi", -qi_wound);
        target->start_busy(2);
        me->start_busy(random(2));
    }
    else
    {
        msg = HIG "ֻ��$n���Ų�æ������һ���������$N�����ݣ�\n"NOR;
        if(userp(me))
            me->add("neili",-100);
        me->start_busy(4);
    }
    message_vision(msg, me, target);
    return 1;
}
