// rose_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	me->receive_wound("qi", 20);
	me->receive_damage("qi", 10);
	me->apply_condition("rose_poison", duration - 1);
	tell_object(me, HIG "���е�" HIR "��õ�嶾" HIG "�����ˣ�\n" NOR );
	if( duration < 1 ) return 0;
	return 1;
}
