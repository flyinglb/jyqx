// huayu.c

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill, i;
        string msg;
        object weapon, *ob;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���컨��ֻ����ս����ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
	     || (string)weapon->query("skill_type") != "throwing")
		return notify_fail("��ʹ�õ��������ԡ�\n");

        if( (int)me->query_skill("feixing-shu", 1) < 100 )
                return notify_fail("��ķ�����������죬����ʹ�����컨�ꡣ\n");
        if( (int)me->query_skill("huagong-dafa", 1) < 100 )
                return notify_fail("��Ļ����󷨲�����죬����ʹ�����컨�ꡣ\n");

        if( (int)me->query("neili") < 300 )
                return notify_fail("�����������ˡ�\n");

        skill = me->query_skill("feixing-shu", 1);

        me->add("neili", -200);
        target->receive_damage("qi", (int)skill/ 3);

        msg="ֻ��һ�ɾ����$N���Ҳ෢����$N���е�"+weapon->name()+"���������$n���ֹ�ȥ��\n";

        me->start_busy(2);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
        {
                msg += "���$p��$P���˸����ֲ�����\n" NOR;
                target->receive_wound("qi", random(skill)*2);
                target->start_busy(random(3));
        } else {
                msg += "����$p�����$P�����һ����\n" NOR;
        }
        message_vision(msg, me, target);
        ob = all_inventory(me);         //use out all throwing
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( (string)ob[i]->query("equipped")!="wielded" ) continue;
        ob[i]->unequip();
                  ob[i]->move(environment(me));
        }
                  me->reset_action();
        return 1;
}

