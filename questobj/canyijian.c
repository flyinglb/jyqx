// chanyijian.c 蝉翼剑

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("蝉翼剑", ({ "chanyi jian","jian" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄绝世宝剑，剑身薄如蝉翼。\n据说当此剑划过自己喉管时，自己根本感觉不到，当你发觉时你已经死了。\n");
		set("value", 100);
		set("material", "steel");
		set("wield_msg", "$N「嗖」的一声不知从哪儿抽出一柄寒光四射的$n握在手中。\n");
		set("unwield_msg", "$N将手中的一挥$n消失得无影无踪。\n");
            set("dynamic_quest", "/d/wuguan/npc/zhang-yufeng");
	}
	init_sword(450);
	setup();
}
