// fengjiang.c ��佬
// By Lgg,1998.9

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("��佬", ({"jiang", "feng jiang"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һƿ����䳲���ɵĽ���\n");
                set("unit", "ƿ");
                set("value", 30);
                set("food_remaining", 3);
                set("food_supply", 40);
        }
}
