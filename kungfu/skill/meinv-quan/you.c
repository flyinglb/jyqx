// you.c ��Ůȭ-��Ĺ�ľ�

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��Ĺ�ľ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("������ȷ������еı�����\n");

        if( (int)me->query_skill("meinv-quan", 1) < 50 )
                return notify_fail("�����Ůȭ���𲻹�������ʹ�ù�Ĺ�ľӡ�\n");

        if( (int)me->query_skill("yunv-xinfa", 1) < 40 )
                return notify_fail("�����Ů�ķ���δ��죬�����������˵С�\n");

        if( (int)me->query("neili", 1) < 150 )
                return notify_fail("����������̫��������ʹ�ù�Ĺ�ľӡ�\n");

        msg = HIW "$N����֧�ã���������ӳ�����̾һ����ʹ������Ĺ�ľӡ������ּ���֮�⡣\n"NOR;

        //if( !target->is_killing(me) ) target->kill_ob(me);

        if (random(me->query_skill("force")) > target->query_skill("force")/2 )
        {
                me->start_busy(random(3));

                damage = (int)me->query_skill("yunv-xinfa", 1) + (int)me->query_skill("meinv-quan",1);
                //(��Ů�ķ�+��Ůȭ����)/2
                damage=damage/2;

                damage = damage/2 + random(damage/2) + random(damage/4);

                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                target->start_busy(3);
                me->add("neili", -100);

                if( damage < 30 )
                        msg += HIY"���$n��$N����һ�����ƺ�һ����\n"NOR;
                else if( damage < 55 )
                        msg += HIY"���$n��$N������һ���������ڡ����˳�������\n"NOR;
                else if( damage < 80 )
                        msg += RED"���$n��$N������һ�����ؿ������ܵ�һ���ش�����ѪΪ֮һ�ϣ�\n"NOR;
                else
                        msg += HIR"���$n��$N������һ������ǰһ�ڣ�������Ѫ���ڣ����������¯һ�㣡\n"NOR;

        }
        else
        {
                me->start_busy(3);
                msg += CYN"����$p������$P����ͼ����Ȼ����̩ɽ��̧��һ�ܸ񿪡�\n"NOR;
        }
        message_vision(msg, me, target);

        return 1;
}
