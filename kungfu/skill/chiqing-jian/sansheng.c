//������ʥ��֮����ʥ��������
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon;
        int damage;        
        weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target || !me->is_fighting(target) )
                return notify_fail("����ʥ������ֻ����ս���жԶ���ʹ�á�\n");
        if (!weapon || weapon->query("skill_type") != "sword")
                return notify_fail("�������ʹ�ý�ʱ����ʹ������ʥ��������\n");
        if( (int)me->query_skill("chiqing-jian", 1) < 120 )
                return notify_fail("��ĳ�����ʥ����������죬ʹ��������ʥ��������\n");
        if( (int)me->query_skill("xuantian-force", 1) < 160 )
                return notify_fail("����ڹ���Ϊ������ʹ��������ʥ��������\n");
        if( (int)me->query_skill("force") < 240 )
                return notify_fail("����ڹ���Ϊ������ʹ��������ʥ��������\n");
        if( (int)me->query_skill("music",1) < 140 )
                return notify_fail("�����������������ʹ��������ʥ��������\n");
        if( (int)me->query_skill("chess",1) < 140 )
                return notify_fail("�����������������ʹ��������ʥ��������\n");
        if( (int)me->query_str() < 30)
                return notify_fail("���������������ʹ��������ʥ��������\n");
        if( (int)me->query_dex() < 30)
                return notify_fail("�������������ʹ��������ʥ��������\n");
        if( (int)me->query("max_neili") < 2000 )
                return notify_fail("����������̫����ʹ��������ʥ��������\n");      
        if( (int)me->query("neili") < 1000 )
                return notify_fail("����������̫����ʹ��������ʥ��������\n"); 
        if( (int)me->query("jingli") < 500 )
                return notify_fail("����������̫����ʹ��������ʥ��������\n"); 
 
        msg = HIC "$N���ֳ���������Ծ�������ƺ������壬�����ڸ��١���\n\n"NOR;
        msg += HIY"$nΪ���������ȣ����ɵý����������裬���������ĵ���˼����\n\n"NOR;
        msg += HIR"Ȼ���⽣���Ѿ�ֱ��$nǰ�أ���ӯ��ݣ��޿ɱ��⡭����\n\n"NOR;
        if (random(me->query_skill("sword"))>(int)target->query_skill("parry")/2)
        {
//              target->start_busy(random(3));
                damage = (int)me->query_skill("chiqing-jian", 1);
                damage = damage +  0.5 * (int)me->query_skill("sword", 1);
                damage = damage +  0.25 * (int)me->query_skill("music", 1);
                damage = damage +  0.25 * (int)me->query_skill("chess", 1);
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage/3);
                target->receive_damage("jing", damage/2);
                target->receive_wound("jing", damage/3);
        msg += HIG"$n����û����ܣ�����ʥ���������ϰ벿�������������Ѿ�����\n\n"NOR;
        msg += HIM"��ֱ�ش���$n�ؿڣ�$nһ��ͷ���ؿڵ���Ѫ�泤����������\n\n"NOR;
                me->add("neili", -500);
                me->add("jingli", -250);
        } else
        {
        msg += HIB"����$p��ת���Σ������ָ��������$P�Ľ��ϣ������д��š���\n\n"NOR;
        msg += HIM"͸�ǵĺ�����$p��໮�����������ˡ�\n\n"NOR;
                me->add("neili", -500);
                me->add("jingli", -250);
        }
        message_vision(msg, me, target);
	if(!target->is_fighting(me)) target->fight_ob(me);

        msg = HIW"\n$N�ϰ��������δ���������е�"+weapon->name()+HIW"��Ȼ������������\n\n"NOR;
	msg += HIY"�����ǡ���ʥ���������°벿���������١���һ����Ϊ������һ������һ������$n��\n\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
              me->add("neili",-500);
              me->add("jingli",-250);    

        me->start_busy(4);
        target->start_busy(4);
        return 1;
}
