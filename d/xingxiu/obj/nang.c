// food: /d/xingxiu/npc/obj/nang.c
// Jay 3/17/96

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("��", ({"nang", "cake"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����ά��������ճ��Ե�һ�����\n");
                set("unit", "��");
                set("value", 50);
                set("food_remaining", 3);
                set("food_supply", 20);
        }
}

