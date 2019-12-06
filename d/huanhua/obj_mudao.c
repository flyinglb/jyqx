// mudao.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("木刀", ({ "mudao" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 10);
		set("material", "iron");
		set("long", "这是一小孩玩的木刀。\n");
		set("wield_msg", "$N抽出一把轻飘飘的$n握在手中　\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘　\n");
	}
	init_blade(1);
	setup();
}
