// liumai.c - ��������
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( me->query_skill("finger") < 150 )
                return notify_fail("����ָ���ϵ����費�����޷�ʹ���������ڡ�\n");
        if( me->query_skill("dodge") < 150 )
                return notify_fail("�����Ṧ�ϵ����費�����޷�ʹ���������ڡ�\n");
        if( me->query("max_neili") < 800 || me->query("neili") < 1500 )
                return notify_fail("��������������޷�ʩչ�������ڣ�\n");
        message_vision(HIW"$N���Ծ��,ʹ���������񽣵���߾����������ڡ�\n" + HIC"������⼲�����������$n������\n"NOR, me, target);
        me->add("neili", -500);
//        me->add("max_neili", -1);
        me->add_temp("apply/strength", 12*(int)me->query("str") );
        me->add_temp("apply/dexerity", 12*(int)me->query("dex") );
        COMBAT_D->do_attack(me, target);
        COMBAT_D->do_attack(me, target);
        COMBAT_D->do_attack(me, target);
        COMBAT_D->do_attack(me, target);
        COMBAT_D->do_attack(me, target);
        COMBAT_D->do_attack(me, target);
        COMBAT_D->do_attack(me, target);
        me->add_temp("apply/strength", -12*(int)me->query("str") );
        me->add_temp("apply/dexerity", -12*(int)me->query("dex") );
        me->start_busy(3);
        return 1;
}
