// hanxing-fada/lastrisk.c

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int i,s;
        string msg;
        object *ob;
        object weapon;
        s = me->query_skill("hanxing-bada", 1);
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��עһ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "throwing")
           return notify_fail("��������а�����\n");

//        if( !(weapon = me->query_temp("weapon")) )
//                return notify_fail("��û��װ��������\n");

        if( s < 60)
                return notify_fail("��ĺ��ǰ˴���Ϊ̫ǳ��\n");
        msg = CYN "$N��עһ�����������а�������$n!";
        me->start_busy(2);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
        {
                msg += "���$p��$P���˸����ֲ�����\n" NOR;
                target->receive_wound("qi", random(s)*2);
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

