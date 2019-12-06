#include <ansi.h>

inherit ITEM;


void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIY "灵芝" NOR, ({"lingzhi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("long", "这是一支产自昆仑山上的灵芝。\n");
		set("value", 50000);
	}
	setup();
}

int do_eat(string arg)
{
	int force_limit, neili_limit ;
	object me = this_player();
	force_limit = me->query_skill("force")*10;
	neili_limit = me->query("max_neili");
	if (!id(arg)||(arg!="lingzhi"))
	return notify_fail("你要吃什么？\n");

	if ( neili_limit <= force_limit  )
	{
		me->add("max_neili",10);
		me->add("neili",10);
		message_vision(HIY "$N吃下一支灵芝，顿然间只觉一股清凉之气直沁心肺...\n" NOR, this_player());
	}
	else
		message_vision(HIY "$N吃下一支灵芝，但是好象没什么用.\n" NOR, this_player());

	destruct(this_object());
	return 1;
}

