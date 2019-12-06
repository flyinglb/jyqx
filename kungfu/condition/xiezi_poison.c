// xiezi_poison.c 蝎子毒

#include <ansi.h>

int update_condition(object me, int duration)
{
        me->receive_wound("jing", 10);
        me->receive_damage("qi", 10);
	me->apply_condition("xiezi_poison", duration - 1);
	tell_object(me, HIR "你中的蝎毒发作了！\n" NOR );
	if( duration < 1 ) return 0;
	return 1;
}
