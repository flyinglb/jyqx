// fotiaoqiang.c
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(RED"����ǽ"NOR, ({"fotiaoqiang"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��������ķ���ǽ���Ǹ�����һ���ˡ�\n");
                set("unit", "��");
                set("value", 500);
                set("food_remaining", 10);
                set("food_supply", 100);
        }
}
