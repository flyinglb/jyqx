// jiaohuaji.c �л���

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�л���", ({"jiaohuaji", "ji", "chicken"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һֻ����������Ľл���\n");
		set("unit", "ֻ");
		set("value", 2000);
		set("food_remaining", 3);
		set("food_supply", 70);
	}
}

