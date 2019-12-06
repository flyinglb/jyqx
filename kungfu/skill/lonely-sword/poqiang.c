// poqiang.c ����ǹʽ��

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, weapon2, target;
        int skill, ap, dp, damage;

//        if(me->query("family/master_id") != "feng qingyang")
//           return notify_fail("�㲻�Ƿ�����ĵ��ӣ�����ʹ�þ��У�\n");

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("lonely-sword",1);

        if( !(me->is_fighting() ))
            return notify_fail("����ǹʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("��ʹ�õ��������ԡ�\n");

        if (!objectp(weapon2 = target->query_temp("weapon"))
        || ((string)weapon2->query("skill_type") != "staff"
        && (string)weapon2->query("skill_type") != "club"))
            return notify_fail("�Է�û��ʹǹ�������ò��ˡ���ǹʽ����\n");

        if( skill < 50)
            return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á���ǹʽ����\n");

        if( me->query("neili") < 50 )
            return notify_fail("��������������޷����á���ǹʽ����\n");

	if((time() - (int)me->query_temp("lonely_time") < 3)){
		write("��ĸ�ʩչ�����¾Ž��ľ��У����ƻ�û���ջء�\n");
	return 1;
	}

        msg = HIC "$Nһʽ���¾Ž�����ǹʽ�����������ɵ�˳��"+weapon2->name()
+"���䣬����$n����ָ��\n";
        message_vision(msg, me, target);
        damage = 10 + random(skill / 2);
        ap = me->query_skill("sword") + skill;
        if((string)weapon2->query("skill_type") == "staff")
            dp = target->query_skill("staff") / 2;
        else if((string)weapon2->query("skill_type") != "club")
            dp = target->query_skill("club") / 2;

        if( dp < 1 )
            dp = 1;
        if( random(ap) > dp )
        {
            if(userp(me))
                 me->add("neili",-50);
            msg = "$N������ǹʽ��, $n��ʱ�󾪣�Ϊ����ָ������";
            msg += weapon2->name();
            msg += "���ֶ�����\n" NOR;

            me->start_busy(random(2));
	     me->set_temp("lonely_time",time());
            target->receive_damage("qi", damage);
            target->start_busy(2);
            weapon2->move(environment(me));
        }
        else
        {
            if(userp(me))
                 me->add("neili",-30);
            msg = "����$n������$N�Ľ�·������������" + weapon2->name()+
"��ǰ���̣���ʹ$N�ջع��ƣ�\n"NOR;
            me->start_busy(random(3));
	     me->set_temp("lonely_time",time());
        }
        message_vision(msg, me, target);

        return 1;
}
