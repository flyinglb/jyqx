#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIG"�����轣ͼ"NOR, ({ "wujiantu", "tu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("material", "paper");
            set("dynamic_quest", "/d/npc/duanyu");
	}
}
