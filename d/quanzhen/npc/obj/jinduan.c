// jinduan.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("����", ({ "jin duan", "jin", "duan" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "˿");
                set("value", 4000);
                set("armor_prop/armor", 3);
        }
        setup();
}

