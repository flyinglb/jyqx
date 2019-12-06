// jinchuang-yao.c ��ҩ

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

	set_name("��ҩ", ({"jin chuangyao", "jin"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������Ч�Ľ�ҩ��ר�������˵ȡ�\n");
		set("value", 2000);
		set("no_drop", "�������������뿪�㡣\n");
	}

	set("shaolin",1);
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");

	if (me->query("eff_qi") == me->query("max_qi"))
		return notify_fail("�����ڲ���Ҫ�ý�ҩ��\n");
	
	if ( (int)me->query_condition("bonze_drug" ) > 0 )
	{
		this_player()->add("eff_qi", -50);
		message_vision(HIR "$N����һ����ҩ��ֻ���ؿڷ�����Ż����֫������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
	else
	{
		this_player()->receive_curing("qi", 50);
		message_vision(HIC "$N����һ����ҩ��ֻ��������������ɫ�������ö��ˡ�\n" NOR, me);
	}

	me->apply_condition("bonze_drug", 15);

	destruct(this_object());
	return 1;

}

