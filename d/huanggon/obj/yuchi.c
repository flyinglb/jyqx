// yuchi.c ���

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("���", ({"yu chi", "yu"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "�ϵ����,ζ������.��ʵҲ����ô����.\n");
                set("unit", "��");
                set("value", 100);
                set("food_remaining", 1);
                set("food_supply", 1);
        }
}
