//Edit by cloth 2000-09-19
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        int extra;
        object weapon;
        extra = me->query_skill("shenyuan-gong",1);
        if ( extra < 100) return notify_fail("�����Ԫ���ȼ�������\n");
        extra = me->query_skill("murong-daofa",1);
        if ( extra < 130) return notify_fail("���Ľ�ݵ������������죡\n");
        if((int)me->query_skill("blade", 1) < 100 )
                return notify_fail("��Ļ�������������죬�����ڵ����м���ʹ�ÿ쵶��\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("������û�е����޷�ʹ�ÿ쵶��\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�쵶ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if ((int)me->query("neili")<150)
                return notify_fail("�������������\n"); 
        me->add("neili",-150);
        weapon = me->query_temp("weapon");
        message_vision(HIY"$Nʹ��Ľ�ݵ����еľ��п쵶�����е�"+weapon->name()+"�������$n������\n\n" NOR,me,target);       
     if (random((int)me->query_skill("dodge", 1)/2)>random((int)target->query_skill("dodge")/5 ) )
        {
        COMBAT_D->do_attack(me,target, weapon); 
        message_vision(HIR"��һ����\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIR"��һ����\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIR"��һ����\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIR"��һ����\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIR"���һ����\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        
        
        message_vision(HIY"���$n�����˸����ֲ�����\n" NOR,me,target);
        me->start_busy(3);
        } else { 
                message_vision(HIY"����$n������$N����ʽ,�û�����������\n" NOR,me,target);
                me->start_busy(1);
        }        
        return 1;
}
