// duo.c ���������
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
    string msg;
    object weapon, weapon2, target;
    int skill, dp;
    me->clean_up_enemy();
    target = me->select_opponent();
     skill = me->query_skill("shexing-diaoshou",1);
    if( !(me->is_fighting() ))
        return notify_fail("���߲���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
    if (objectp(weapon = me->query_temp("weapon")) && objectp(weapon = me->query_temp("weapon")))
        return notify_fail("�������֡�\n");
    if (!objectp(weapon2 = target->query_temp("weapon")))
        return notify_fail("�Է�û�б��У�������߲��������κ�����.\n");
    if( skill < 50)
       return notify_fail("������ε��ֵȼ�����, �������߲���\n");
    if( me->query("neili") < 50 )
       return notify_fail("��������������޷�ʹ�����߲���\n");
 
     msg = CYN "$N��Ϣ������Ѹ�ټӿ죬ʹ�������ε��ֵľ���--���߲��� \n";
    message_vision(msg, me);
 
     dp = target->query("combat_exp") / 5000;
    if( dp < 1 )
        dp = 1;
    if( random(skill) > dp )
    {
        if(userp(me))
            me->add("neili",-50);
msg = CYN "$n���������Ӱ��֪���룬����һ�飬���б������ֶ�����\n" NOR;
        target->start_busy(2);
        weapon2->move(me);
        me->start_busy(2);
    }
    else
    {
        msg = "����$n����Ӧս��$N�����߲���û�����κ����á�\n"NOR;
        me->start_busy(4);
    }
    message_vision(msg, me, target);
    return 1;
}
