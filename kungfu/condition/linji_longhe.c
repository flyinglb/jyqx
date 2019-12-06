// linji_longhe.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( duration == 0 )
	{
		tell_object(me, 
HIB "��Ȼ�����ȫ��������ģ�����СָͷҲ���붯�ˣ�ԭ�����
����ׯ�չ��ˣ�\n" NOR );
		me->add("con", 0 - me->query("linji/con"));
		me->delete("linji/con");
		return 0;
	}
	me->apply_condition("linji_longhe", duration - 1);

	return CND_CONTINUE;
}
