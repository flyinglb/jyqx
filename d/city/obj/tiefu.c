// gangjian.c

#include <weapon.h>
inherit AXE;

void create()
{
        set_name("斧头", ({ "fu tou", "axe" }));
        set_weight(15000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
                set("long", "这是一把砍柴用的斧头，做武器好象差了点。\n");
                set("value", 500);
		set("material", "steel");
                set("wield_msg", "$N从后腰拔出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n别到了腰后面。\n");
	}
        init_axe(10,0);
	setup();
}
