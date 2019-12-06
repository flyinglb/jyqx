inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
	set_name(HIW"天赋膏"NOR, ({"tianfu gao","gao"}));
	set_weight(3000);
	set("unit", "块");
	set("long", "这是一块可以改变天赋的药品。\n");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();

	if (!(arg))  return notify_fail("你要吃什么？\n");
	if(arg=="gao")
	{
		write(HIC"你吃下了一块天赋膏，只觉得身体发生了一些变化。\n"NOR);
		me->add("combat_exp",150000);
		me->add("potential",30000);
//		me->add("max_neili",60000);
//		me->add("neili",60000);
//              me->add("score",2000);
//              me->add("mud_age",43200);
//		me->add("per",13);
//		me->add("kar",17);
		destruct(this_object());
		me->unconcious();
	}
	return 1;
}
