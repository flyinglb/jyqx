// basi-shanyao.c ��˿ɽҩ

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��˿ɽҩ", ({"basi shanyao", "shanyao"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��ɫ��õ�壬�������۵İ�˿ɽҩ��\n");
		set("unit", "��");
		set("value", 150);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
