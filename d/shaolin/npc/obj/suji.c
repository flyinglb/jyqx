// suji.c �ؼ�

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�ؼ�", ({"suji", "ji"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һֻ���������ؼ���\n");
		set("unit", "ֻ");
		set("value", 150);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
