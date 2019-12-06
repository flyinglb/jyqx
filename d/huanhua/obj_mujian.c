// sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("木剑", ({ "mujian" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "口");
		set("value", 10);
		set("material", "iron");
		set("long", "这是一小孩玩的木剑。\n");
		set("wield_msg", "$N抽出一把轻飘飘的$n握在手中　\n");
		set("unequip_msg", "$N将手中的$n插入腰间的剑鞘　\n");
	}
	init_sword(1);
	setup();
}
