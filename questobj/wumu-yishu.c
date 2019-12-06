#include <ansi.h>
inherit ITEM;
void create()
{
	set_name( HIC"武穆遗书"NOR, ({ "wumu yishu", "yishu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
			GRN
			"\n这就是岳武穆临死前留下的“破金要诀”。\n"
			"只见第一页上写了十八个大字：\n"
                        "“重搜选，谨训习”\n"
                        "“公赏罚，明号令”\n"
                        "“严纪  ，同甘苦”\n"
               NOR
		);
		set("value", 10000000);
		set("material", "paper");
            set("dynamic_quest", "/d/npc/guojing");
	}
}
