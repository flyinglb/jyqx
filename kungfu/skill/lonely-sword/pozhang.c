// pozhang.c ������ʽ��

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, weapon2, target;
        int skill, ap, dp, wound;

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

        if (objectp(weapon2 = target->query_temp("weapon")))
            return notify_fail("�Է������������������ò��ˡ�����ʽ����\n");

        if( skill < 70)
            return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á�����ʽ����\n");

        if( me->query("neili") < 50 )
            return notify_fail("��������������޷����á�����ʽ����\n");

	if((time() - (int)me->query_temp("lonely_time") < 3)){
		write("��ĸ�ʩչ�����¾Ž��ľ��У����ƻ�û���ջء�\n");
	return 1;
	}

        msg = HIC "$Nʹ�����¾Ž�֮������ʽ��, �������ڽ��⣬��ͼ����ʹ��.\n";
        message_vision(msg, me, target);

        ap = me->query("combat_exp") + skill * 1000;
        dp = target->query("combat_exp") / 4;
        if( dp < 1 )
            dp = 1;
        if( random(ap) > dp )
        {
            if(userp(me))
                 me->add("neili",-50);
            msg = "$N��������ʽ��, $n��ʱ������ǰһ��������һ������������һ
�ؽ���ð�˳�����\n"NOR;

//            wound = 60 + random(skill);
            wound = (int)me->query_skill("sword",1)/2 + skill;
            wound = wound/2 + random(wound);
// modify by Java
            if( wound > (int)target->query("qi"))
                wound = (int)target->query("qi");
            me->start_busy(random(2));
	     me->set_temp("lonely_time",time());
//            target->add("qi", -wound);
//            target->add("eff_qi", -wound);
            target->receive_damage("qi", wound);
            target->receive_wound("qi", wound/2);
// modify by Java
            target->start_busy(2);
        }
        else
        {
            if(userp(me))
                me->add("neili",-100);
            msg = "����$n������$N����ͼ��ȫ�����أ�������ס��$N�Ĺ��ơ�\n"NOR;
	     me->set_temp("lonely_time",time());
        }
        message_vision(msg, me, target);
        return 1;
}
