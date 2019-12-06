inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
	set_name(HIG"岁月"HIY"金丹"NOR, ({"age dan","dan"}));
	set_weight(3000);
	set("unit", "粒");
	set("long", "这是天山童姥为葆青春，采无数珍贵药材精致而成的丹药。\n");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();

	if (!(arg))  return notify_fail("你要吃什么？\n");
	if(arg=="dan")
	{
                if ((int)me->query("mud_age")>=2246400) 
                {
			write(HIW"你吃下了一粒"HIG"岁月"HIY"金丹"HIW"，觉得好象年轻了一些。\n"NOR);
			me->add("mud_age",-86400);
			me->add("age",-1);
			destruct(this_object());
			me->unconcious();
		}
		else {
			write(HIG"岁月"HIY"金丹"RED"可能炼制得不是特别合适，你吃下去没起什么作用。\n"NOR);
			destruct(this_object());
		}
	}
	return 1;
}
