// yangxin.c ������

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("������", ({"yangxin wan", "wan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ű��췢���������衣\n");
		set("value", 10000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	this_player()->add("qi", 200);
	message_vision("$N����һ�������裬ֻ������������ԴԴ�������������ơ�\n", this_player());
	destruct(this_object());
	return 1;
}


