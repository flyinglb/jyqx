               // tongpi.c ͭƤ

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( HIY"ͭƤ"NOR, ({ "tong pi", "pi"}) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "leather");
                set("armor_prop/armor", 100);
        }
        setup();
}

void owner_is_killed()
{
        destruct(this_object());
} 
