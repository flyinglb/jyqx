// mitao.c ˮ����
// By Marz

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ˮ����", ({"tao", "mi tao"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��ˮ�����ʵ�ˮ���ҡ�\n");
		set("unit", "��");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
