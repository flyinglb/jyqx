//kuang.c 
// Modified by Venus Oct.1997
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int extra;
        object weapon;
    string msg;
        extra=me->query_skill("tiexue-hammer",1);
    if( !target ) target = offensive_target(me);
    if( !target||!target->is_character()||!me->is_fighting(target) )
    return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á��񴸡���\n");
    if( (int)me->query_skill("tiexue-hammer",1) < 70)
    return notify_fail("��Ŀǰ������ʹ�������񴸡���\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "hammer")
                        return notify_fail("��ʹ�õ��������ԡ�\n");
        if( (int)me->query("neili") < 100 )
    return notify_fail("�������������\n");
    me->add("neili", -60);
    msg = HIR"$N���һ����������������һ˲֮�䣬"+
    "$N���ҳ��������������ŷ磬���ŷ�Ӱ��$nֻ����ȫ����Ѫ������"NOR;
        message_vision(msg, me, target);                
        msg = HIY  "---��һ����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "-----�ڶ�������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "-------���һ����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->start_busy(2);


    return 1;
}


