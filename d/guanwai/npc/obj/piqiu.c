// piqiu.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("Ƥ��", ({ "piqiu" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500);
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
}

