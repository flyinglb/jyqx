// cimu.c ��Ŀ

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[��Ŀ]ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
                
        if( (int)me->query_skill("pixie-jian", 1) < 90 )
                return notify_fail("��ı�а����������죬����ʹ�á���Ŀ����\n");
                                
        if( (int)me->query_skill("kuihua-xinfa", 1) < 50 )
                return notify_fail("��Ŀ����ķ������ߣ���������[��Ŀ]��\n");
                        
        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("����������̫��������ʹ�á���Ŀ����\n");
                        
        msg = HIC "$N¶�����ȵ�Ц�ݣ�����Ʈ��,�������,���Ժ������$n���۾���ȥ��\n"NOR;

        if( !target->is_killing(me) ) target->kill_ob(me);

        if (random(me->query_skill("force")) > target->query_skill("force")/6 )
        {
                target->start_busy( (int)me->query_skill("pixie-jian") / 80 + 1);
                
                damage = (int)me->query_skill("kuihua-xinfa", 1);
                damage = damage +  (int)me->query_skill("kuihua-xinfa", 1);
                damage = damage +  (int)me->query_skill("pixie-jian", 1);
                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                me->add("neili", -damage/2);
                msg += HIC"ֻ��$N���н���ó��߰˸�$N,�ڿն���,ٿ�Ĵ���$n���۾�,\n$n������ң�ֻ���۾�һ���ʹ����Ѫ���۾�˳����������������\n"NOR;
                me->start_busy(2);
        } else 
        {
                msg += HIY"$n�鼱������̧��Ҳ��$P��ȥ���ȵ�$P�ؽ�Ծ���ջ����С���Ŀ����\n"NOR;
                me->add("neili", -100);
                me->start_busy(2);
        }
        message_vision(msg, me, target);

        return 1;
}

