// jue.c ����

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[����]ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
                
        if( (int)me->query_skill("huifeng-jian", 1) < 90 )
                return notify_fail(WHT"��Ļط��������������죬����ʹ�á���������\n");
                                
        if( (int)me->query_skill("linji-zhuang", 1) < 90 )
                return notify_fail(RED"����ټ�ʮ��ׯ�����ߣ���������[����]��\n");
                        
        if( (int)me->query("neili", 1) < 500 )
                return notify_fail(YEL"����������̫��������ʹ�á���������\n");
                        
        msg = HIG "$N���н����Ȼ��ʧ�ڿ��У�����������һ˲�䣬��ʧ�Ľ���ȴ\n"NOR;
        msg += HIG "�ѻ���������Ӱ�۵���$n��ǰ��ȴ����ͻȻ֮��ת��$n\n"NOR;
        msg += HIG "�����š��ʺ�̴�С��������������Ҫ������һ�����Խ���\n"NOR;
        msg += HIG "������ʬ��\n\n"NOR;

        if( !target->is_killing(me) ) target->kill_ob(me);

        if (random(me->query_skill("sword")) > target->query_skill("dodge")/6 )
        {
                target->start_busy( (int)me->query_skill("huifeng-jian") / 70 + 1);
                
                damage = (int)me->query_skill("huifeng-jian", 1);
                damage = damage +  (int)me->query_skill("huifeng-jian", 1);
                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                target->receive_damage("jing", damage/2);
                target->receive_wound("jing", damage/3);
                me->add("neili", -damage);
                msg += HIR"ֻ��$N���н�����$n���ϻû�������Ѫ����\n$nֻ������ÿһ���ֶ�Ҫ���Լ���ȥ��\n"NOR;
                me->start_busy(3);
        } else 
        {
                msg += HIG"$n�鼱������̧��Ҳ��$P��ȥ���ȵ�$P�ؽ�Ծ���ջ����о�����\n"NOR;
                me->add("neili", -100);
                me->start_busy(3);
        }
        message_vision(msg, me, target);

        return 1;
}

