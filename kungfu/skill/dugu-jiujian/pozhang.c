// pozhang.c ������ʽ��
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
    string msg;
    object weapon, weapon2, target;
    int skill, ap, dp, wound;
    me->clean_up_enemy();
    target = me->select_opponent();
    skill = me->query_skill("dugu-jiujian",1);
    if( !(me->is_fighting() ))
        return notify_fail("������ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if (objectp(weapon2 = target->query_temp("weapon")))
        return notify_fail("�Է������������������ò��ˡ�����ʽ����\n");
    if( skill < 70)
        return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á�����ʽ����\n");
    if( me->query("neili") < 50 )
        return notify_fail("��������������޷����á�����ʽ����\n");
 
    if (me->query_temp("perform"))
        return notify_fail("����һ��û���, ����ʹ�á�����ʽ����\n");
    msg = HIC "$Nʹ�����¾Ž�֮������ʽ��, ���������ڽ��⣬��ͼ����ʹ��. \n";
    message_vision(msg, me, target);
 
    ap = me->query("combat_exp")+skill*skill;
    dp = target->query("combat_exp") / 2;
    if( dp < 1 )
        dp = 1;
    if( random(ap) > dp )
    {
        if(userp(me))
            me->add("neili",-50);
        msg = "$N��������ʽ��, $n��ʱ������ǰһ��������һ�����������Ķ��˸�Ѫ������\n"NOR;
        wound = 60 + random(skill);
        if( wound > (int)target->query("qi"))
        wound = (int)target->query("qi");
    
        
        target->add("qi", -wound);
        target->add("eff_qi", -wound);
        target->start_busy(2);
    }
    else
    {
        if(userp(me))
            me->add("neili",-30);
        msg = "����$n������$N����ͼ��ȫ�����أ�������ס��$N�Ĺ��ơ�\n"NOR;
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
