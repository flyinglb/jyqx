inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("������", ({"laoshu rou", "rou"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ����Ѫ����ʵ������⡣\n");
                set("unit", "��");
                set("value", 200);
                set("food_remaining", 4);
                set("food_supply", 50);
        }
}

