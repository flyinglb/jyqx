// fugu.c ����������-���ǲ���

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
//        object weapon;
//        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("���ǲ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_temp("weapon"))
                return notify_fail("�㲻�ǿ��֣�����ʹ�ø��ǲ���\n");

        if( (int)me->query_skill("jinshe-zhang", 1) < 100 )
                return notify_fail("��Ľ����Ʋ�����죬����ʹ�ø��ǲ���\n");

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("����������̫��������ʹ�ø��ǲ���\n");

        msg = HIC "$N���һ���������������һ̽��ס$n������������ɱ�֣�\n"NOR;
        message_vision(msg, me, target);

        if( !target->is_fighting(me) ) target->fight_ob(me);

        if (random(me->query_skill("strike")) > target->query_skill("dodge")/2 )
        {
                me->clean_up_enemy();
                target = me->select_opponent();

                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);

                me->add("neili", -50);
                me->start_busy(random(2));
                msg = HIR"���$n��$N���������ƣ��ڡ����ǲ����£���Ȼ�޷����֣�\n"NOR;
        }
        else
        {
                me->start_busy(3);
                msg = CYN"����$pʶ����$P��һ�У�����һ�ͣ������˶Է����ơ�\n"NOR;
        }
        message_vision(msg, me, target);

        return 1;
}
