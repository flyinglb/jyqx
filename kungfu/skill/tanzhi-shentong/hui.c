// hui.c �ӳⷽ��
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
    string msg;
    object weapon, target;
    int skill, dp, wound;
    me->clean_up_enemy();
    target = me->select_opponent();
    skill = me->query_skill("tanzhi-shentong",1);
    if( !(me->is_fighting() ))
        return notify_fail("���ӳⷽ�١�ֻ����ս����ʹ�á�\n");
    if ( objectp(weapon = me->query_temp("weapon")) && objectp(weapon = me->query_temp("secondary_weapon")))
        return notify_fail("�����ճ�һ���ֲ���ʹ�õ�ָ��ͨ��\n");
    if( skill < 50)
        return notify_fail("��ĵ�ָ��ͨ�ȼ�����, ����ʹ�á��ӳⷽ�١���\n");
    if( me->query("neili") < 150 )
        return notify_fail("��������������޷����á��ӳⷽ�١���\n");
 
    msg = HIC "$Nʹ����ָ��֮ͨ���ӳⷽ�١�, ��ʱ���ھ��Ⱪ�䣬\n";
    message_vision(msg, me, target);
 
    dp = target->query_skill("force",1) / 2;
    if( dp < 1 )
        dp = 1;
    if( random(skill) > dp )
    {
        if(userp(me))
            me->add("neili",-150);
        msg = "$nֻ������ǰһ��������Ѩ��΢΢һʹ��ȫ��������й������\n" NOR;
        wound = -300 - random(200);
        if((int)target->query("neili") < wound)
            wound = target->query("neili");
        target->add("neili", wound);
        target->add("jing", wound / 5);
        target->start_busy(2);
        me->start_busy(2);
    }
    else
    {
        msg = "����$n�Ŀ�����$N����ͼ�����̲�ȡ���ƣ�ʹ$P�ġ��ӳⷽ�١�û�������á�\n"NOR;
        me->start_busy(4);
    }
    message_vision(msg, me, target);
    return 1;
}
