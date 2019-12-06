// wineskin.c  �ƴ�

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("ţƤ�ƴ�", ({"jiudai", "wineskin", "skin"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������װ�׾ƵĴ�ƴ������װ�ðˡ������ľơ�\n");
		set("unit", "��");
		set("value", 20);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "�׾�",
		"remaining": 15,
		"drunk_supply": 6,
	]));
}

