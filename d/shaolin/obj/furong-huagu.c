// furong-huagu.c ܽ�ػ���

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ܽ�ػ���", ({"furong huagu", "huagu"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������֭Ũ��ζ��ˬ�ڵ�ܽ�ػ�������\n");
		set("unit", "��");
		set("value", 150);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
