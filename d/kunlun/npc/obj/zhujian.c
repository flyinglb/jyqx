// zhujian.c 
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("竹剑", ({ "zhu jian","jian","sword" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄普通的竹剑剑，一般的是用来练习武功用的。\n");
		set("value", 100);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n收起来。\n");
	}
	init_sword(5);
	setup();
}
