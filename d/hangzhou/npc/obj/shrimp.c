// shrimp.c ����Ϻ��
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(RED"����Ϻ��"NOR, ({"shrimp"}));
        set_weight(1300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����ŨŨ��һ������Ϻ�ʡ�\n");
                set("unit", "��");
                set("value", 50);
                set("food_remaining", 5);
                set("food_supply", 20);
        }
}
