// wuji.c ��Ԫ�޼�
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
    string msg;
    object weapon, target;
    int skill, ap, dp, neili_wound, qi_wound;
    me->clean_up_enemy();
    target = me->select_opponent();
    skill = me->query_skill("hunyuan-zhang",1);
    if( !(me->is_fighting() ))
        return notify_fail("����Ԫ�޼���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
    if (objectp(weapon = me->query_temp("weapon")))
        return notify_fail("��ʹ����������\n");
    if( skill < 60)
        return notify_fail("��ġ���Ԫ�ơ��ȼ�����, ����ʹ�á���Ԫ�޼�����\n");
    if( me->query("neili") < 150 )
        return notify_fail("��������������޷����á���Ԫ�޼�����\n");
 
    msg = HIC "$NǱ�ˡ���Ԫ�޼�����˫ȭЮ�������ķ���֮����$n��ȥ��\n"NOR;
    message_vision(msg, me, target);
 
    ap = me->query("combat_exp") + skill * 400;
    dp = target->query("combat_exp") / 2;
    if( dp < 1 )
        dp = 1;
    if( random(ap) > dp )
    {
        if(userp(me))
            me->add("neili",-100);
        msg = HIG "$nֻ������ǰһ���ʹ�����ۡ���һ�����һ����Ѫ��\n"NOR;
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
        msg = HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
        if(userp(me))
            me->add("neili",-100);
        me->start_busy(4);
    }
    message_vision(msg, me, target);
    return 1;
}
