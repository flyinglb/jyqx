// linji_zhixin.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( duration == 0 )
	{
		tell_object(me, 
HIB "��Ȼ��ͷ����е�һ��հף�ԭ�����֮��ׯ�չ��ˣ����ʱ
�����Լ����Ǹ���ľ�ϣ�\n" NOR );
		me->add("int", 0 - me->query("linji/int"));
		me->delete("linji/int");
		return 0;
	}
	me->apply_condition("linji_zhixin", duration - 1);

	return CND_CONTINUE;
}
