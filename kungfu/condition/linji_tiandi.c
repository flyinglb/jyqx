// linji_tiandi.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( duration == 0 )
	{
		tell_object(me, 
HIB "��Ȼ������ͷ�е�һ��ʧ�䣬ԭ��������ׯ�չ��ˣ����ʱ
���к�����ȥ֮̾��\n" NOR );
		me->add("per", 0 - me->query("linji/per"));
		me->delete("linji/per");
		return 0;
	}
	me->apply_condition("linji_tiandi", duration - 1);

	return CND_CONTINUE;
}
