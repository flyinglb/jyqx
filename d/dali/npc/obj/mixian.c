// mixian.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��������", ({"guoqiao mixian", "mixian"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ���������ڵ��ͽ����׷ۣ����Ǵ������˹������ߡ�\n");
		set("unit", "��");
		set("value", 80);
		set("food_remaining", 10);
		set("food_supply", 20);
	}
}
