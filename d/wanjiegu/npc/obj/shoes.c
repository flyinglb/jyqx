// shoes.c example shoes

#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name( GRN "�廨Ь" NOR, ({ "shoes" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("value", 100);
                set("material", "cloth");
                set("armor_type", "feet");
                set("armor_prop/personality", 1);
                set("armor_prop/armor", 2);
                set("armor_prop/dodge", 2);
                set("female_only", 1);
                set("wear_msg","$N����һ˫$n��\n");
                set("remove_msg","$N��$n����������\n");
        }
}
