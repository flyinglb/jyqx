// food: yangrou.c
// Jay 3.18/96

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("���⴮", ({"yangrou chuan", "yangrou", "chuan"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ������������⴮������մ������Ȼ�������档\n");
                set("unit", "��");
                set("value", 200);
                set("food_remaining", 3);
                set("food_supply", 50);
        }
}

