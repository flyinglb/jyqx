// hitback.c

#include <ansi.h>

inherit F_CLEAN_UP;

//void remove_effect(object me, int amount);
void remove_effect(object me);

int exert(object me, object target)
{
        int skill;
        int three_skill;

        if( !me->is_fighting() )
           return notify_fail("转力之术只能在战斗中使用。\n");
        if( target != me ) return
           notify_fail("你只能用乾坤挪移神功转开对自己的攻击。\n");
        if( (int)me->query("force") < 50 ) return notify_fail("你的内力不够。\n");
        if( me->query_temp("shift") ) return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");
        me->add("force", -50);
        //me->receive_damage("sen", 20);
        write("你心念一转，运起了乾坤大挪移神功，打算把敌人的攻击转回给他自己。\n");
        me->set_temp("shift", "hitback");
        three_skill = me->query_skill("shiftforce", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :),
           three_skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me)
{
  if (me->query_temp("shift") == "hitback")
	{
	me->delete_temp("shift");
      tell_object(me, "你的乾坤大挪移神功运行完毕，将内力收回丹田。\n");
     }
}
 
