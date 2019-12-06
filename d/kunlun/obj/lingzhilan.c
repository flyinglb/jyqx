#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIC "灵脂兰" NOR, ({"lingzhilan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("long", "这是一支带有毒球根的灵脂兰。\n");
		set("value", 0);
	}
	setup();
}
