// Jay 5/23/96

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����", ({"zongzi"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��������������ӣ�����������Ҷ����һ�����㡣\n");
                set("unit", "��");
                set("value", 100);
                set("food_remaining", 3);
                set("food_supply", 50);
        }
}

