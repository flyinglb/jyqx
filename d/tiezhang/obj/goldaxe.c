#include <weapon.h>

inherit AXE;

void create()
{
        set_name(HIY "金斧"NOR, ({ "gold axe", "axe" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("material", "steel");
                set("long", "这是一把用金子做成大斧子，锋利无比，但十分沉重。\n");
		set("value", 500);
                set("no_put", 1);
                set("no_drop", 1);
                set("no_give", 1);
//                set("no_get", 1);
                set("wield_msg", HIY "金光一闪，只见$N手多了一把$n。\n"NOR);
                set("unwield_msg", "$N放下手中的$n。\n");
	}
        init_axe(500, TWO_HANDED);
	setup();
}

