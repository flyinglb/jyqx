// Jay 5/23/96

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("������", ({"marz"}));
        set_weight(70);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "�����˿�����Ϊ�����˵�ʳƷ��\n");
                set("unit", "ֻ");
                set("food_remaining", 19);
                set("food_supply",1 );
        }
}

