// fish.c ��������
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(RED"��������"NOR, ({"fish"}));
        set_weight(1300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��������˵��������㣬�������еĽ�ɫ����
���ƶ��ɣ���������һ���ˡ�\n");
                set("unit", "��");
                set("value", 120);
                set("food_remaining", 20);
                set("food_supply", 20);
        }
}
