// wine.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("�Ʊ�", ({"wine"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "��û���壬���²���á�\n");
		set("unit", "��");
		set("value", 100);
		set("no_get", "1");
		set("max_liquid", 5);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "�׾�",
		"remaining": 5,
		"supply": 15,
		"drunk_apply": 3,
	]));
}
