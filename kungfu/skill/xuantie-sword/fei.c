#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int extra,i,time;
        string msg;
        extra = me->query_skill("xuantie-sword",1);
        time = extra/40; 
        if( !target ) target = offensive_target(me);
if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ɺ���硹ֻ����ս����ʹ�á�\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("��ʹ�õ��������ԡ�\n");
//        if( (string)weapon->query("id") != "xuantiesword" )
//                return notify_fail("�������õĲ�����������\n");
        if((int)me->query_skill("sword") < 230)
                return notify_fail("��Ľ�����Ϊ������ Ŀǰ����ʹ�÷ɺ����! \n");
        weapon = me->query_temp("weapon");
        if( (int)me->query("neili") < 500 )
                return notify_fail("�������������\n");
        msg = HIR  "$N���������һ��������̤���沨�����е�"+ weapon->name()+  HIR"�����ػ���һ�������$n������" NOR;
    if( !living(target) || random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
    {
        message_vision(msg,me,target);
//      me->add_temp("apply/attack",extra/5);
//      me->add_temp("apply/damage",extra/5);
       for(i = 0; i < 8; i++)
        {
        msg =  YEL "$N�������飬�����ݺᣡ\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
//      me->add_temp("apply/attack",-extra/4);
//      me->add_temp("apply/damage",-extra/4);
        me->add("neili",-500);
        me->start_busy(3);
    }
    else {

         msg += HIY"����$p"+ HIY +"������$P����ͼ����û���ϵ���\n" NOR;
        }
        me->start_busy(2);
    message_vision(msg, me, target);
        return 1;
}
