// ni-cloth.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIC"�಼���"NOR, ({ "zi yi", "cloth" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ�������˴����಼��¡�\n");
                set("material", "cloth");
		set("value", 0);
                set("armor_prop/armor", 8);
		set("female_only", 1);
        }
        setup();
}

