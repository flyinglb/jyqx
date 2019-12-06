#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(GRN"ÇàË¿½í"NOR, ({ "qingsijin" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Ìõ");
		set("value", 1);
		set("material", "paper");
            set("dynamic_quest", "/kungfu/class/taohua/huang");
	}
}
