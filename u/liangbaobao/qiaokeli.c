// qiaokeli.c 
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIY"���˽ڵ��ɿ���"NOR, ({"qiao keli", "keli"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "���˽��͸����˵��ɿ�����\n");
                set("unit", "��");
                set("value", 50);
                set("food_remaining", 1);
                set("food_supply", 500);
        }
}


