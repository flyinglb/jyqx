// zhizhu_poison.c ֩�붾

#include <ansi.h>

int update_condition(object me, int duration)
{
        me->receive_wound("jing", 10);
        me->receive_damage("qi", 10);
	me->apply_condition("zhizhu_poison", duration - 1);
	tell_object(me, HIW "���е�֩�붾�����ˣ�\n" NOR );
	if( duration < 1 ) return 0;
	return 1;
}
