// fish.c

inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("�����", ({ "fish" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һβ����㣬����һ�ߡ�\n");
		set("unit", "β");
		set("value", 30);
		set("food_remaining", 4);
		set("food_supply", 40);
		set("material", "bone");
	}
	setup();
}

int finish_eat()
{
	set_name("���", ({ "fish bone" }) );
	set_weight(150);
	set("long", "һ���еþ�������ͷ�������ӿ������롣\n");
	return 1;
}
