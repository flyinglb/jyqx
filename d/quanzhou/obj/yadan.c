// yadan.c 
// Jay 5/23/96

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("��Ѽ��", ({"chou yadan", "yadan", "egg"}));
        set_weight(70);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "��Ѽ�����ų��������㡣\n");
                set("unit", "��");
                set("value", 80);
                set("food_remaining", 1);
                set("food_supply", 80);
        }
}

