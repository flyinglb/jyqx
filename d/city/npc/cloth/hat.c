// hat.c example belt

#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name( HIY "ӧ��ñ" NOR, ({ "hat" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 300);
                set("material", "cloth");
                set("armor_type", "head");
                set("armor_prop/personality", 1);
                set("armor_prop/armor", 4);
                set("armor_prop/dodge", -1);
                set("wear_msg","$N����һ��$n��\n");
                set("remove_msg","$N��$n����������\n");
        }
}
