// guoqiaomixian.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>;

void create()
{
	set_name(HIG"Ҷ����"NOR, ({"ye er ba", "ba"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ��Ʈ�������Ҷ���Ρ�\n");
		set("unit", "��");
		set("value", 100);
		set("food_remaining", 15);
		set("food_supply", 20);
	}
}
