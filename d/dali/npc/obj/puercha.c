// puercha.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("���", ({"chahu", "hu", "bottle"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������װ��Ĵ��������װ�ðˡ��ű��Ĳ衣\n");
		set("unit", "��");
		set("value", 150);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "water",
		"name": "�����ն���",
		"remaining": 15,
		"drunk_apply": 5,
	]));
}
