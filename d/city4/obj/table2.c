#include <ansi.h>

inherit ITEM;


void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIW"明目丹"NOR, ({"mingmu dan", "dan","mingmu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "粒");
		set("long", "这是一粒珍贵的明目丹。\n");
		set("value", 200);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	
	if (!id(arg)||(arg!="dan"&&arg!="mingmu dan"))
	return notify_fail("你要吃什么？\n");
	me->add("eff_jing",10000);
	me->add("max_jing",10000);
	message_vision(HIW "$N吃下一粒明目丹，顿然间只觉一股清凉之气自双目透出...\n" NOR, this_player());
	destruct(this_object());
	return 1;
}

