// jiaohuaji.c �л���

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�л���", ({"jiaohua ji", "ji"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һֻ���������ͣ���ζ�˱ǵĽл�����\n");
		set("unit", "ֻ");
		set("value", 200);
		set("food_remaining", 1);
		set("food_supply", 100);
	}
}
