// sanxiao_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	me->receive_wound("qi", 500);
	me->receive_damage("qi", 500);
	me->apply_condition("sanxiao_poison", duration - 1);
message_vision(HIG"$N���Ϻ�Ȼ¶�������һЦ��������"HIB"��Ц��ңɢ"HIG"�����ˣ�\n" NOR, me);
	if( duration < 1 ) return 0;
	return 1;
}
