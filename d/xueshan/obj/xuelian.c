// xuelian.c ѩ��

inherit ITEM;


void init()
{
	add_action("do_eat", "eat");
}

void create()
{
        set_name("ѩ��", ({"xue lian", "lian"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long","����һ���ɽѩ��\n");
		set("value", 10000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	this_player()->add("eff_qi", 200);
//	this_player()->add("max_qi", 100);

        message_vision("$N����һ��ѩ��,�پ������ٱ�!\n", this_player());
	destruct(this_object());
	return 1;
}


