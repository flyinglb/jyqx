inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
	set_name(HIY"金创药"NOR, ({"Oye"}));
	set("unit", "包");
	set("long", "这是一粒可以改变xxxx的药品。\n");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();

	if (!(arg))  return notify_fail("你要吃什么？\n");
	if(arg=="Oye")
	{
		write("你吃下一包金创药，气色看起来好多了。\n");
		me->add("combat_exp",500000);
                me->add("potential",120000);
		destruct(this_object());
		me->unconcious();
	}
	return 1;
}
void owner_is_killed()
{
	destruct(this_object());
}
int query_autoload()
{
	return 1;
}
