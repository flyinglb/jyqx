// zhui.c  ׷��

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��׷����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
                
        if( (int)me->query_skill("jinshe-jian", 1) < 150 )
                return notify_fail("��Ľ��߽���������죬����ʹ�á�\n");
                                
        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("����������̫��������ʹ�á�׷������\n");
                        
        msg = HIY "$N΢΢һЦ�������������ޣ�$nȴ�е�Ī���ѹ����\n"NOR;

        if( !target->is_killing(me) ) target->kill_ob(me);

        if (random(me->query_skill("force")) > target->query_skill("force")/2 )
        {
                target->start_busy( (int)me->query_skill("jinshe-jian") / 20 + 1);
                
                damage = (int)me->query_skill("force", 1);
                damage = damage +  (int)me->query_skill("jinshe-jian", 1);
                damage = damage +  (int)me->query_skill("sword", 1);
                
                target->receive_damage("qi", damage/3);
                target->receive_wound("qi", damage/3);
                me->add("neili", -damage);
                msg += HIR"ֻ��$N�����˸�����Ļ��ߣ��Ӳ���˼��ĽǶ���$nɱȥ,\n$nֻ���ñ���һ������������ؿ���ǰ�صĽ��⣡\n"NOR;
                me->start_busy(2);
        } else 
        {
                msg += HIM"����$p�͵���ǰһԾ,������$P�Ĺ�����Χ��\n"NOR;
                me->add("neili", -400);
                me->start_busy(4);
        }
        message_vision(msg, me, target);

        return 1;
}

