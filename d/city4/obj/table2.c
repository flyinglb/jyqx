#include <ansi.h>

inherit ITEM;


void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIW"��Ŀ��"NOR, ({"mingmu dan", "dan","mingmu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������Ŀ����\n");
		set("value", 200);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	
	if (!id(arg)||(arg!="dan"&&arg!="mingmu dan"))
	return notify_fail("��Ҫ��ʲô��\n");
	me->add("eff_jing",10000);
	me->add("max_jing",10000);
	message_vision(HIW "$N����һ����Ŀ������Ȼ��ֻ��һ������֮����˫Ŀ͸��...\n" NOR, this_player());
	destruct(this_object());
	return 1;
}

