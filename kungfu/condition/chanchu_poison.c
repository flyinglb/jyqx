// chanchu_poison.c ��ܶ�

#include <ansi.h>

int update_condition(object me, int duration)
{
        me->receive_wound("jing", 10);
        me->receive_damage("qi", 10);
	me->apply_condition("chanchu_poison", duration - 1);
	tell_object(me, HIB "���е���ܶ������ˣ�\n" NOR );
	if( duration < 1 ) return 0;
	return 1;
}
