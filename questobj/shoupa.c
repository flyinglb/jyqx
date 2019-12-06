#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIG"手帕"NOR, ({ "shoupa" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("value", 1);
		set("material", "paper");
		set("long","这是一条段延庆受刀白凤恩惠留下的。"NOR);
            set("dynamic_quest", "/d/npc/duanyanqing");
	}
}
