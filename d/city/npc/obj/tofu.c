// tofu.c ����

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��䶹��", ({"doufu", "tofu"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��ˮ����Ĵ󶹸����۵����˲����뵽����ɩ����������\n");
		set("unit", "��");
		set("value", 40);
		set("food_remaining", 1);
		set("food_supply", 50);
	}
}
