// shanhu-baicai.c ɺ���ײ�

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ɺ���ײ�", ({"shanhu baicai", "baicai"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������䣬����ˬ�ڣ��������˵�ɺ���ײˡ�\n");
		set("unit", "��");
		set("value", 150);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
