// cloth.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("�಼ɮ��", ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

