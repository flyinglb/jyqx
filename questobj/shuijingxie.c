#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIM"ˮ��Ь"NOR, ({ "shuijingxie" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("value", 10000);
		set("material", "ˮ��");
            set("dynamic_quest", "/d/city/yingying");
	}
}
