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
        if ( extra < 100) return notify_fail("�����Ԫ�����������죡\n");
        extra = me->query_skill("murong-jianfa",1);
        if ( extra < 100) return notify_fail("���Ľ�ݽ������������죡\n");
        if((int)me->query_skill("sword", 1) < 100 )
        return notify_fail(RED"������������������콣��������ʽ��\n"NOR);
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�ۿ콣��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if ((int)me->query("neili")<250)
                return notify_fail("�������������\n"); 
        me->add("neili",-250);
        weapon = me->query_temp("weapon");
        message_vision(HIM"$Nʹ��Ľ�ݽ����еľ��Уۿ콣�ݣ�һ���������������е�"+weapon->name()+"
�������$n����������\n\n" NOR,me,target);   
     if (random((int)me->query_skill("dodge", 1)/2)>random((int)target->query_skill("dodge")/5 ) 
)
        {
        COMBAT_D->do_attack(me,target, weapon); 
        message_vision(HIW"��һ����\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIC"�ڶ�����\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIR"��������\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIY"���Ľ���\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIB"���彣��\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);


        message_vision(WHT"$N�������������$n�����˸���æ���ң�\n" NOR,me,target);
        me->start_busy(2);
        } else { 
                message_vision(HIC"����$n������$N����ʽ,�û�����������\n" NOR,me,target);
                me->start_busy(1);
        }        
        return 1;
}
