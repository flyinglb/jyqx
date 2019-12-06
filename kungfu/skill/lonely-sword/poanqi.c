// poanqi.c �Ƽ�ʽ

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, weapon2, target;
        int skill, ap, dp, damage;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("lonely-sword",1);

//        if(me->query("family/master_id") != "feng qingyang")
//           return notify_fail("�㲻�Ƿ�����ĵ��ӣ�����ʹ�þ��У�\n");

        if( !(me->is_fighting() ))
            return notify_fail("���Ƽ�ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("��ʹ�õ��������ԡ�\n");

        if (!objectp(weapon2 = target->query_temp("weapon"))
        || (string)weapon2->query("skill_type") != "throwing")
             return notify_fail("�Է�û��ʹ���������ò��ˡ��Ƽ�ʽ����\n");

        if( skill < 50)
            return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á��Ƽ�ʽ����\n");

        if( me->query("neili") < 50 )
            return notify_fail("��������������޷����á��Ƽ�ʽ����\n");

	if((time() - (int)me->query_temp("lonely_time") < 3)){
		write("��ĸ�ʩչ�����¾Ž��ľ��У����ƻ�û���ջء�\n");
	return 1;
	}


        msg = HIC "$N�ٽ����㣬������¾Ž�֮���Ƽ�ʽ��, ��$n��������"+
weapon2->name() + "�����$n������ȥ��\n";
        message_vision(msg, me, target);

        damage = 10 + random(skill / 2);
        ap = me->query_skill("sword") + skill;
        dp = target->query_skill("throwing", 1);
        if( dp < 1 )
                dp = 1;
          if( random(ap) > dp )
          {
             if(userp(me))
                  me->add("neili",-50);
             msg = "$n��ʱ��������ǵص�";
             msg += weapon2->name();
             msg += "�������Լ�Ϯ����ȫ���������̱���ø�������Ƶ�\n" NOR;

             me->start_busy(random(2));
	     me->set_temp("lonely_time",time());
             target->receive_damage("qi", damage);
             target->start_busy(2);
        }
        else
        {
             if(userp(me))
                  me->add("neili",-30);
             msg = "����$n������$N����ͼ�����̽�����" + weapon2->name()+
"��÷��겻͸��������������" + weapon2->name() + "���������ڵء�\n"NOR;
             me->start_busy(random(3));
	     me->set_temp("lonely_time",time());
        }
        message_vision(msg, me, target);

        return 1;
}
