// huotui.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>;

void create()
{
	set_name(HIR"��������"NOR, ({"xuanwei huotui", "huotui"}));
	set_weight(280);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ�����۽�������������ź��͵���������������ȡ�\n");
		set("unit", "��");
		set("value", 200);
		set("food_remaining", 10);
		set("food_supply", 30);
	}
}
