// food: /d/xingxiu/npc/obj/hamigua.c
// Jay 3/18/96

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("���ܹ�", ({"hamigua", "gua", "melon"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ������Ĺ��ܹϡ����Թ��ܹϵ��ڰ�������\n");
                set("unit", "��");
                set("value", 40);
                set("food_remaining", 1);
                set("food_supply", 50);
        }
}

