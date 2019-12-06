
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("貂皮大衣", ({ "diaopi dayi", "cloth" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "一件选用上好貂皮精工缝制的大衣。\n");
                set("material", "cloth");
		set("value", 100000);
                set("armor_prop/armor", 5);
        }
        setup();
}

