// ju.c �����-�����۶�


#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
//        object weapon;
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("�����۶�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("haotian-zhang", 1) < 50 )
                return notify_fail("�������Ʋ�����죬����ʹ�������۶���\n");

        if( (int)me->query("neili", 1) < 150 )
                return notify_fail("����������̫��������ʹ�������۶���\n");

        msg = HIC "$N���һ����������$n���ϣ�˫��ͬʱ��������һ�С������۶�����\n"NOR;

        if( !target->is_killing(me) ) target->kill_ob(me);

        if (random(me->query_skill("force")) > target->query_skill("force")/2 )
        {
                me->start_busy(1);
                
                damage = (int)me->query_skill("haotian-zhang", 1) + (int)me->query_skill("force",1);
                //(����Ƽ���+�����ڹ�) 
                        
                damage = damage/2 + random(damage/2) ;
                
                target->receive_damage("qi", damage);
                target->start_busy(4);
                me->add("neili", -100);
                
                msg += HIR"���$n��$N���������㣬һ��֮�£���Ȼ���˵ֵ���\n"NOR;
                
        }
        else 
        {
                me->start_busy(3);
                msg += CYN"����$pʶ����$P��һ�У�ббһԾ�ܿ���\n"NOR;
        }
        message_vision(msg, me, target);

        return 1;
}
