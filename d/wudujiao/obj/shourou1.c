// shourou1.c ������

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("������", ({"paozi rou", "rou"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���ɵ����⡣\n");
		set("unit", "��");
		set("value", 20);
		set("food_remaining", 15);
		set("food_supply", 100);
	}
}
