// mangguo.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("â��", ({"guo", "mangguo"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�����ʵ�â�����������˴������Ρ�\n");
                set("unit", "��");
                set("value", 80);
                set("food_remaining", 4);
                set("food_supply", 30);
        }
}

