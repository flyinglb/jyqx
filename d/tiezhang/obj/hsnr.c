// hsnr.c ����ţ��

inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("����ţ��", ({"hongshao niurou", "niurou"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
        set("long", "һ�����ú��ú����ţ�⣬������ֱ����ˮ��\n");
        set("unit", "��");
		set("value", 150);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}

