// renshen.c

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("�˲�", ({"renshen", "shen"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ó������ε���ɽ�Ρ�\n");
		set("value", 10000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	this_player()->add("max_neili", 3);
	message_vision("$N����һ����ɽ�Σ���ʱ�����ȫ������˻��� !\n", this_player());
	destruct(this_object());
	return 1;
}

