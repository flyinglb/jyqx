// egg.c 

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�����Ҷ��", ({"spicy egg", "egg"}));
	set_weight(60);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���������������Ƴ����Ĳ�Ҷ����\n");
		set("unit", "��");
		set("value", 50);
		set("food_remaining", 1);
		set("food_supply", 50);
	}
}
