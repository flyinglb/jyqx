// poqi.c ����ʽ
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
    string msg;
    object weapon, target;
    int skill, ap, dp, neili_wound, qi_wound;
    me->clean_up_enemy();
    target = me->select_opponent();
    skill = me->query_skill("dugu-jiujian",1);
    if( !(me->is_fighting() ))
        return notify_fail("������ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if( skill < 90)
        return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á�����ʽ����\n");
    if( me->query("neili") < 150 )
        return notify_fail("��������������޷����á�����ʽ����\n");
    
     if (me->query_temp("perform"))
        return notify_fail("����һ��û���, ����ʹ�á�����ʽ����\n");
    msg = HIC "$NǱ�˶��¾Ž�������ʽ���������ὣʹ���������ۣ����޻��ε�ֱ��$n�ĵ��\n";
    message_vision(msg, me, target);
 
    ap = me->query("combat_exp")+skill*skill;
    dp = target->query("combat_exp") / 2;
    if( dp < 1 )
        dp = 1;
    if( random(ap) > dp )
    {
        if(userp(me))
            me->add("neili",-150);
        msg = "$N��������ʽ��, $n��ʱ������ǰһ��������Ѩ��΢΢һʹ��\n";
        msg += "ȫ��������й������\n" NOR;
        neili_wound = 300 + random(skill);
        if(neili_wound > target->query("neili"))
            neili_wound = target->query("neili");
        qi_wound = neili_wound / 5;
        if(qi_wound > target->query("qi"))
            qi_wound = target->query("qi");
        target->add("neili", -neili_wound);
        target->add("qi", -qi_wound);
        target->add("eff_qi", -qi_wound);
        target->start_busy(2);
    }
    else
    {
        if(userp(me))
            me->add("neili",-100);
        msg = "����$n������$N����ͼ�������ؽ��Ż��������������ڻ��е�����\n"NOR;
    }
    me->set_temp("perform",1);
    call_out("perform_end",1,me);
    message_vision(msg, me, target);
    return 1;
}
void perform_end(object me)
{
    if (!me)    return;
    me->delete_temp("perform");
}
