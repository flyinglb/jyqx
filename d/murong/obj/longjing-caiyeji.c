// /u/beyond/mr/obj/longjing-caiyeji.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"������Ҷ��"NOR, ({"longjing caiyeji", "ji"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��������Ŀɿڵ�������Ҷ����\n");
                set("unit", "��");
                set("value", 150);
                set("food_remaining", 4);
                set("food_supply", 40);
        }
}

