// he.c ��Ů��-˫�����

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("˫�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if( (int)me->query_skill("yunv-xinfa", 1) < 80 )
                return notify_fail("�����Ů�ķ�������죬����ʹ��˫����赡�\n");

        if( (int)me->query_skill("yunv-jian", 1) < 80 )
                return notify_fail("�����Ů����������죬����ʹ��˫����赡�\n");

        if( (int)me->query_skill("quanzhen-jian", 1) < 50 )
                return notify_fail("���ȫ�潣��������죬����ʹ��˫����赡�\n");

        if( (int)me->query("neili", 1) < 400 )
                return notify_fail("����������̫��������ʹ��˫����赡�\n");

        msg = YEL "$N������ȫ�潣�����⣬���ֻ���Ů�������У�˫�����ͬʱ�̳���\n"NOR;

        if( !target->is_fighting(me) ) target->fight_ob(me);

        if (random(me->query_skill("force")) > target->query_skill("force")/2 )
        {
                me->start_busy(2);

                damage = (int)me->query_skill("yunv-jian", 1) + (int)me->query_skill("quanzhen-jian",1);
                damage = damage + (int)me->query_skill("force",1) ;
                //(��Ů����+ȫ�潣������+�����ڹ�)

                damage = damage/2 + random(damage);

                target->receive_damage("qi", damage);
                target->start_busy(4);
                me->add("neili", -350);

                msg += HIR"$n����$N˫�����裬��ʽ������������Ϊ��һ����ȥ������֪
����Ǻã�\n"NOR;
                msg += HIR"һ��֮�£�$N�Ľ����Ѿ���ʽ���룡\n"NOR;

        }
        else
        {
                me->start_busy(3);
                msg += CYN"����$p������$P����ͼ�����Լ���ȫ�����»����ܲ�͸�磬
��$P�޼ƿ�ʩ��\n"NOR;
        }
        message_vision(msg, me, target);

        return 1;
}
