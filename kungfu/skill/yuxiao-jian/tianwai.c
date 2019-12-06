// tianwai.c ��������

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
//        int skill, ap, dp, neili_wound, qi_wound;
        int skill, ap, dp, qi_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("yuxiao-jian",1);

        if( !(me->is_fighting() ))
            return notify_fail("������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("��ʹ�õ��������ԡ�\n");

        if( me->query_skill("bibo-shengong",1) < 120)
            return notify_fail("��ı̲��񹦵ȼ�����, ����ʹ�á�������������\n");

        if( skill < 90)
            return notify_fail("������｣���ȼ�����, ����ʹ�á�������������\n");

        if( me->query("neili") < 250 )
            return notify_fail("��������������޷����á�������������\n");

        msg = HIC 
"$Nһ����Х����������������һ����������������һʽ��������������\n"+weapon->name()
+HIC+"������ֹ����Ӱ��ҹĻ������$n��\n";
        message_vision(msg, me, target);

        ap = me->query_skill("sword") + skill;
        dp = target->query_skill("force") / 4;
        if( dp < 1 )
            dp = 1;
        if( random(ap) > dp )
        {
            if(userp(me))
                 me->add("neili",-150);
            msg = "$n��ʱ������ǰ�����������˫��������������֪����һ���ʹ������һ�㣡\n" NOR;
           qi_wound = (int)me->query_skill("yuxiao-jian",1)+(int)me->query_skill("sword",1)+0.5*(int)me->query_skill("music",1);
            qi_wound = qi_wound/2 + random(qi_wound);
            if(qi_wound > target->query("qi"))
                 qi_wound = target->query("qi");

            target->receive_damage("qi", qi_wound);
            target->receive_wound("qi", qi_wound/2);
            target->start_busy(2);
            me->start_busy(2);
        }
        else
        {
            if(userp(me))
                 me->add("neili",-100);
            msg = "����$n���ľ��������ֻ�������$N������Ʋ��һ�ߡ�\n"NOR;
            me->start_busy(random(3));
        }
        message_vision(msg, me, target);
        if(!target->is_fighting(me)) target->fight_ob(me);
        return 1;
}
