// maotan.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("ë̺", ({ "mao tan" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
		set("value", 2000);
                set("armor_prop/armor", 2);
        }
        setup();
}

