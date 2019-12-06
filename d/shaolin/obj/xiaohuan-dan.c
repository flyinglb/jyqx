// xiaohuan-dan.c С����

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("С����", ({"xiaohuan dan", "xiaohuan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��Ө����Բ��С�������˵���������ҩ��������������Ч�ޱȡ�\n");
		set("value", 10000);
		set("no_drop", "�������������뿪�㡣\n");
	}

	set("shaolin",1);
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	if ( me->query("neili") >= me->query("max_neili")*2 )
		return notify_fail("������û��Ҫ��С������\n");

	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	me->start_busy(2);
	if ( me->query_skill_mapped("force") != "hunyuan-yiqi" )
	{
		me->set("neili", 0);
		message_vision(HIR "$N����һ��С������ֻ�����������ѣ�ԭ�������ڹ�����������������Ϊ��\n" NOR, me);
//		me->unconcious();
		destruct(this_object());
		return 1;
	}

	if ( (int)me->query_condition("bonze_drug" ) > 0 )
	{
		me->add("neili", -200);
		message_vision(HIR "$N����һ��С������ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
	else
	{
		me->add("neili", 200);
		message_vision(HIY "$N����һ��С������ֻ�����������࣬��֫�ٺ�������ӯ�ޱȣ��������ڶ�����\n" NOR, me);
	}

	me->apply_condition("bonze_drug", 30);

	destruct(this_object());
	return 1;
}


