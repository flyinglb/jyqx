// huluobu.c ���Ჷ
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("���Ჷ��", ({"hu luobu", "luobu"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�������˵ĺ��Ჷ�ɣ��ȽϷ��㴢�ء�\n");
		set("unit", "��");
		set("value", 20);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
}
