// /u/beyond/mr/obj/meihua-zaoya.c ÷����Ѽ
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"÷����Ѽ"NOR, ({"meihua zaoya", "ya"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�����ۿɿڵ�÷����Ѽ��\n");
                set("unit", "��");
                set("value", 150);
                set("food_remaining", 4);
                set("food_supply", 40);
        }
}

