// qiaokeli.c 
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIY"情人节的巧克力"NOR, ({"qiao keli", "keli"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "情人节送给情人的巧克力。\n");
                set("unit", "快");
                set("value", 50);
                set("food_remaining", 1);
                set("food_supply", 500);
        }
}


