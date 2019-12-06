// autosave.c

#include <condition.h>
#include <ansi.h>

int update_condition(object me, int duration)
{
	if (duration == 1)
	{
		tell_object(me, HIG"�����̡����ĵ����Ѿ��Զ����̡�\n"NOR);
//		tell_object(me, HIR"��ϵͳ������ʮһ�����գ���ʱ����ͣ�硣���½⡣\n"NOR);
		me->save();
		me->apply_condition("autosave", duration + 1);
	}
	else
	if (duration == 4)
	{
		if (me->query("food") <= 10)
			tell_object(me, HIY"�����ͷ���ۻ�������Ҫ�Ͽ��ҵ�Ե��ˡ�\n"NOR);
		me->apply_condition("autosave", duration + 1);
	}
	else
	if (duration == 7)
	{
		if (me->query("water") <= 10)
			tell_object(me, HIY"��ʵú���ð�̣�����Ҫ�Ͽ�ȵ�ʲô�ˡ�\n"NOR);
		me->apply_condition("autosave", duration + 1);
	}
	else
	{
		if (duration == 13)  me->apply_condition("autosave", 1);
		else me->apply_condition("autosave", duration + 1);
	}
	return CND_CONTINUE;
}
