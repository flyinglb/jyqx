#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(WHT"白手绢"NOR, ({ "baishoujuan" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("value", 1);
		set("material", "paper");
		set("long","杨过送给小龙女的礼物。"NOR);
            set("dynamic_quest", "/d/gumu/longnv");
	}
}
