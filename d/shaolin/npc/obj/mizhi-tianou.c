// bocai-fentiao.c ��֭��ź

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��֭��ź", ({"mizhi tianou", "tianou"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��������Ŵ��ɫ��ۺ����֭��ź��\n");
		set("unit", "��");
		set("value", 150);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
