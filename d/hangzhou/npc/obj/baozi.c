// baozi.c
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"�ٹ��Ͱ�"NOR, ({"baozi", "dumpling"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ������ͳγΡ�������İٹ��Ͱ���\n");
                set("unit", "��");
                set("value", 70);
                set("food_remaining", 3);
                set("food_supply", 20);
        }
}
