// bashi.c ������ ��ʽ��һ


#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object target, int aamount, int damount);

int perform(object me, object target)
{
//        object weapon;
        int damage;
        string msg;
//        int count,d_count,qi, maxqi, skill;

        if( !target ) target = offensive_target(me);

        if( !me->is_fighting() )
                return notify_fail("����ʽ��һ��ֻ����ս����ʹ�á�\n");
        if( (int)target->query_temp("bashi") )
                return notify_fail("���Ѿ����˹����ˡ�\n");
        if( (int)me->query("neili") < 200 )
                return notify_fail("��������������ߣ�\n");
        if( (int)me->query_skill("linji-zhuang", 1) < 40)
                return notify_fail("����ټ�ʹ��ׯ����Ϊ����������ʹ�ð�ʽ��һ!\n");
        if( (int)me->query_skill("jinding-zhang",1) <100)
                return notify_fail("��Ľ����Ƶİ�ʽ��ϰ��ȫ���޷�ʹ�ð�ʽ��һ��\n");
        if( me->query_skill_mapped("strike") != "jinding-zhang")
                return notify_fail("��û�м��������ƣ��޷�ʹ�ð�ʽ��һ��\n");
        if( !target->is_killing(me) ) target->kill_ob(me);

        msg = HIY "$N��������һ����������ȫ��Ĺ�����˫�ƣ�ֻ����$N����һ���죡\n" NOR;
//        me->start_busy(1);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
        {
                damage = (int)me->query_skill("linji-zhuang", 1)/2;
                damage = damage +  (int)me->query_skill("jinding-zhang", 1);
                target->set_temp("bashi", 1);
                target->add_temp("apply/attack", -damage/3);
                target->add_temp("apply/dodge", -damage/3);
//              target->receive_damage("qi", damage);
//              target->receive_wound("qi", damage/2);
                msg += HIR "$N�ڿն���ʹ���ˡ���ʽ��һ�����������Ӱ��Ʈ������������$nȫ�������λ��\n" NOR;
                me->start_call_out( (: call_other, __FILE__, "remove_effect",target,damage/3, damage/3:), damage/30);
                me->add("neili",-100);
                target->start_busy(3);
         }
         else {
                msg += CYN"����$p�͵���ǰһԾ,������$P�Ĺ�����Χ��\n"NOR;
                me->start_busy(1);
         }
         message_vision(msg, me, target);
         return 1;
}

void remove_effect(object target,int aamount, int damount)
{
               target->add_temp("apply/attack", aamount);
               target->add_temp("apply/dodge", damount);
               target->delete_temp("bashi");
               message_vision(HIG"$N�����ҵĹ����а����˳�������������,��ס�˽Ų�\n"NOR, target);
}

