// fan.c ���׷�

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("���׷�", ({"mi fan", "fan"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��������Ĵ��׷���\n");
		set("unit", "��");
		set("value", 30);
		set("food_remaining", 3);
		set("food_supply", 30);
	}
}
