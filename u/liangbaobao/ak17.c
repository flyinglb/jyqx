
#include <weapon.h>
inherit AXE;

void create()
{
        set_name("AK-47", ({ "qiang", "AK-47" }));
        set_weight(15000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把很好用的冲锋枪.。\n");
                set("value", 500);
                set("material", "steel");
                set("wield_msg", "$N从后腰掏出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n别到了腰后面。\n");
        }
        init_axe(500000,0);
        setup();
}

