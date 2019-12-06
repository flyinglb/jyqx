// flower_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	if(me->query_temp("nopoison")) return 0;
	me->receive_wound("jing", 20);
	me->receive_damage("qi", 10);
	me->apply_condition("flower_poison", duration - random(5));
	tell_object(me, HIG "���е�" HIR "�ϳ�����" HIG "�����ˣ�\n" NOR );
	if( duration < 1 ) return 0;
	return 1;
}
