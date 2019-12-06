#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("羊皮袄", ({ "yangpi ao", "ao"}) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是一件普通的羊皮袄。\n");
                set("material", "cloth");
                set("armor_prop/armor", 3);
                set("value", 200);
        }
        setup();
}

