// poqi.c ����ʽ

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, neili_wound, qi_wound;

//        if(me->query("family/master_id") != "feng qingyang")
//           return notify_fail("�㲻�Ƿ�����ĵ��ӣ�����ʹ�þ��У�\n");

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("lonely-sword",1);

        if( !(me->is_fighting() ))
            return notify_fail("������ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("��ʹ�õ��������ԡ�\n");

        if( skill < 90)
            return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á�����ʽ����\n");

        if( me->query("neili") < 250 )
            return notify_fail("��������������޷����á�����ʽ����\n");

	if((time() - (int)me->query_temp("lonely_time") < 3)){
		write("��ĸ�ʩչ�����¾Ž��ľ��У����ƻ�û���ջء�\n");
	return 1;
	}

        msg = HIC "$NǱ�˶��¾Ž�������ʽ���������ὣʹ���������ۣ����޻��ε�ֱ
��$n�ĵ��\n";
//        message_vision(msg, me, target);
        message_vision(msg, me, target);

        ap = me->query_skill("sword") + skill;
        dp = target->query_skill("force") / 2;
        if( dp < 1 )
            dp = 1;
        if( random(ap) > dp )
        {
            if(userp(me))
                 me->add("neili",-150);
            msg = "$N��������ʽ��������б���Է�С����$n��ʱ������ǰһ��������\n";
            msg += "Ѩ��΢΢һʹ��ȫ��������й������\n" NOR;
            neili_wound = 300 + random(skill);
            if(neili_wound > target->query("neili"))
                 neili_wound = target->query("neili");
            qi_wound = (int)me->query_skill("lonely-sword",1)+(int)me->query_skill("sword",1)/2;
            qi_wound = qi_wound/2 + random(qi_wound);
            if(qi_wound > target->query("qi"))
                 qi_wound = 100;

            target->add("neili", -neili_wound);
            target->add("qi", -qi_wound);
            target->add("eff_qi", -qi_wound);
            target->receive_damage("qi", qi_wound);
            target->receive_wound("qi", qi_wound/2);
            target->start_busy(2);
            me->start_busy(random(3));
	     me->set_temp("lonely_time",time());
        }
        else
        {
            if(userp(me))
                 me->add("neili",-100);
            msg = "����$n������$N����ͼ�������ؽ��Ż��������������ڻ��е�����\n"NOR;
            me->start_busy(random(4));
	     me->set_temp("lonely_time",time());
        }
//        message_vision(msg, me, target);
        message_vision(msg, me, target);

        return 1;
}
