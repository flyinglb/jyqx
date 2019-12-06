#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIM"Ë®¾§Ð¬"NOR, ({ "shuijingxie" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Ë«");
		set("value", 10000);
		set("material", "Ë®¾§");
            set("dynamic_quest", "/d/city/yingying");
	}
}
