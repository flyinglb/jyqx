// food.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ʳ��", ({"food"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "��û���壬���²���á�\n");
		set("unit", "��");
		set("value", 40);
		set("no_get", "1");
		set("food_remaining", 5);
		set("food_supply", 15);
	}
}
