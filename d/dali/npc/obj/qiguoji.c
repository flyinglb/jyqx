// qiguoji.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("������", ({"qiguo ji", "chicken", "ji"}));
	set_weight(280);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ���������ڵ���������\n");
		set("unit", "��");
		set("value", 200);
		set("food_remaining", 10);
		set("food_supply", 40);
	}
}
