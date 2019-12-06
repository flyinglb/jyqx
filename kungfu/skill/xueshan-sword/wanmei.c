#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, qi_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("xueshan-sword",1);

        if( !(me->is_fighting() ))
            return notify_fail("��"+HIW"��÷Ʈ��"NOR+"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("��ʹ�õ��������ԡ�\n");

        if( skill < 80)
            return notify_fail("���ѩɽ������Ϊ����, ����ʹ�á�"+HIW"��÷Ʈ��"NOR+"����\n");  
        if( (int)me->query_skill("bingxue-xinfa",1) < 80 )
                return notify_fail("��ı�ѩ�ķ�����������ʹ�á�"+HIW"��÷Ʈ��"NOR+"����\n");

        if( me->query("neili") < 200 )
            return notify_fail("��������������޷����á�"+HIW"��÷Ʈ��"NOR+"����\n");

        msg = HIW 
    "$N��Хһ��,ʹ������÷Ʈ�㡹,���б�������,�������ѩ����ǰ����ǵص���ȥ��\n"
    "�ڰ�ãã��һƬ��,��Ȼ�������÷���ν���,��͸ѩĻ,������˷����������\n" NOR;
//      message_combatd(msg, me, target);
        message_vision(msg, me, target);

        ap = me->query_skill("sword",1) + skill;
        dp = target->query_skill("dodge",1) / 2;
        if( dp < 1 )
            dp = 1;
        if( random(ap) > dp )
        {
            if(userp(me))
                 me->add("neili",-150); 
        msg = HIC 
    "����÷���⻪,�ó���������,��$nȫ�������ֵ�����ʵʵ��$n��������,\n"
    "ֻ����������,���Լ�����˿˿����,һʱȫ���ʹ,��Ѫ�ɽ��õ������ǡ���ͬ���֮��,\n"
    "�Ҳ����ԡ�\n" NOR; 
        COMBAT_D->report_status(target);
            qi_wound = (int)me->query_skill("xueshan-sword",1)+(int)me->query_skill("sword",1);
            qi_wound = qi_wound/2 + random(qi_wound);
            if(qi_wound > target->query("qi"))
                 qi_wound = target->query("qi");

            target->receive_damage("qi", qi_wound);
            target->receive_wound("qi", qi_wound/2);
            target->receive_damage("jing", qi_wound/3);
            target->receive_wound("jing", qi_wound/5);
            target->start_busy(2+random(1));
            me->start_busy(1+random(1));
        }
        else
        {
            if(userp(me))
                 me->add("neili",-100);
            msg = "����$n��ݵ����Ա�һ�����ܹ�����һ����\n"NOR;
            me->start_busy(2);
        }
        message_vision(msg, me, target);

        return 1;
}

