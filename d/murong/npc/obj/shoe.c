// /u/beyond/mr/obj/shoe.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <armor.h>
inherit BOOTS;
//inherit EQUIP;
void create()
{
        set_name(GRN"̤ѩ�޺�"NOR, ({ "shoes", "xie" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long","����һ˫С�ɵ�Ů��Ь��\n");
                set("unit", "˫");
                set("value", 0);
		set("no_transfer",1);
                set("material", "cloth");
                set("armor_type", "feet");

        }
}

