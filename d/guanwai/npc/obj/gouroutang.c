// gouroutang.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("������", ({"gourou tang", "tang"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������һ�빷�����Ĵ��룬����һ�����ˡ�\n");
		set("unit", "��");
		set("value", 200);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "water",
		"name": "������",
		"remaining": 25,
		"drunk_apply": 5,
	]));
}
