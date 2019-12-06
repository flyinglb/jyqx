// HU.c �ɺ�����
// 
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
//        string msg, string1;
        string msg;
//        int count;
 
        if( !target ) target = offensive_target(me);

        if((int)me->query_str() < 30)
                return notify_fail("����������������㻹������!\n");

        if( !me->is_fighting() )
                return notify_fail("���ɺ����֡�ֻ����ս����ʹ�á�\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");
 
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("���ɺ����֡��������ŵ�����ʹ����\n");

        if( (int)me->query("neili") < 200 )
                return notify_fail("�������������\n");

        if( (int)me->query_skill("blade") < 50 ||
            me->query_skill_mapped("blade") != "hujia-dao")
                return notify_fail("��ĺ��ҵ����������ң��޷�ʹ�÷ɺ����֣�\n");

    if( !living(target) || random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
    {
        msg = HBRED "$Nʹ�������ؼ����ɺ����֡���������Ȼ�ӿ죡\n" NOR;
        message_vision(msg, me);

        me->clean_up_enemy();
        ob = me->select_opponent();

        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        me->add("neili", -200);
        me->start_busy(3);
        ob->start_busy(random(5));
    }
    else
    {
       msg = HIY  "����$p"+ HIY +"������$P����ͼ����û���ϵ���\n" NOR;
         me->start_busy(3);
    }

        return 1;
}

