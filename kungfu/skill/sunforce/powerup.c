// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me ) return 
notify_fail("你只能提升自己的战斗力。\n");

        if( (int)me->query("force") < 100 )     return 
notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") ) return 
notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");

        me->add("bellicosity", 100 + skill/2 );
        me->add("force", -100);
        me->receive_damage("kee", 0);

        message_vision(
                RED 
"$N气沉丹田，深吸了一口气，运起光明神功，全身骨节发出一阵爆豆般的声响！\n" NOR, me);

        me->add_temp("apply/attack", skill/2);
        me->add_temp("apply/dodge", skill/2);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/2 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        message_vision("$N的光明神功运行完毕，缓缓地将内力收回了丹田。\n",me);
}
 
