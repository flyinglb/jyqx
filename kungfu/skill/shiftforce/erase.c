// erase.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;
        int double_skill;
        int amount;

        if( !me->is_fighting() )
           return notify_fail("化力之术只能在战斗中使用。\n");
        if( target != me ) return
           notify_fail("你只能用乾坤挪移神功化对自己的攻击。\n");
        if( (int)me->query("force") < 30 ) return notify_fail("你的内力不够。\n");
        if( me->query_temp("shift") ) return notify_fail("你已经在运功中了。\n");

        skill = (int)me->query_skill("force");

        me->add("force", -30);
        write("你心念一转，运起了乾坤大挪移神功，打算把敌人的攻击化得无影无踪。\n");
        //me->add_temp("apply/dodge", skill * 10);
        me->add_temp("apply/parry", skill * 10);
        me->set_temp("shift", "erase");
        //me->receive_damage("sen",10);
        double_skill = me->query_skill("shiftforce", 1);
        amount = skill * 10;
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
           amount :), double_skill);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
   if (me->query("shift") == "erase" )
      { me->add_temp("apply/parry", - amount);
        //me->add_temp("apply/dodge", - amount);
        me->delete_temp("shift");
        tell_object(me, "你的乾坤大挪移神功运行完毕，将内力收回丹田。\n");
      }
}
 
