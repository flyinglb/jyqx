// jinshe-jianfa perform
//by snowman

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int j, z;
        object weapon;
        j = me->query_skill("xuantie-sword", 1);
        z = me->query_skill("yunv-xinfa", 1);
 
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("��Ѹ�ס�ֻ����ս���жԶ���ʹ�á�\n");

        if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "xuantie-sword"
               || me->query_skill_mapped("parry") != "xuantie-sword")
                return notify_fail("�������ʹ�ý�ʱ����ʹ����Ѹ�ס���\n");

        if(me->query_skill("xuantie-sword", 1) < 100 )
                return notify_fail("�������������������죬ʹ������Ѹ�ס���\n");

        if( (int)me->query_skill("yunv-xinfa", 1) < 160 )
                return notify_fail("�����Ů�ķ���Ϊ������ʹ������Ѹ�ס���\n");

        if( (int)me->query_skill("force") < 160 )
                return notify_fail("����ڹ��ȼ�������ʹ������Ѹ�ס���\n");

        if( (int)me->query_str() < 25)
                return notify_fail("���������������ʹ������Ѹ�ס���\n");

        if( (int)me->query_dex() < 30)
                return notify_fail("�������������ʹ������Ѹ�ס���\n");                                                                               

        if( (int)me->query("max_neili") < 1800 )
                return notify_fail("����������̫����ʹ������Ѹ�ס���\n");      

        if( (int)me->query("neili") < 800 )
                return notify_fail("����������̫����ʹ������Ѹ�ס���\n"); 
                if( (int)me->query("jingli") < 400 )
                return notify_fail("����������̫����ʹ������Ѹ�ס���\n"); 
//      me->add_temp("apply/strength", z/6);
//      me->add_temp("apply/attack", j/6); 
 
        msg = HIW"\n$N�����е�"+weapon->name()+"������$nһѹ����Ȼ����һ���� һ����Ϊ���������籼�׳��繥��$n��\n\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
 

              me->add("neili",-z*2);
              me->add("jingli",-z);    

//      me->add_temp("apply/strength", -z/6);
//      me->add_temp("apply/attack", -j/6);

        me->start_busy(3);
        target->start_busy(1);
        return 1;
}
