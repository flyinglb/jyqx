// birdie.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����", ({"niao", "bird"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ����������⣬�����������\n");
                set("unit", "��");
                set("value", 180);
                set("food_remaining", 5);
                set("food_supply", 50);
        }
}

