// cloth.c
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(BLK"黑色圣衣"NOR, ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long","这是一件绣着红色火焰的黑色圣衣。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

