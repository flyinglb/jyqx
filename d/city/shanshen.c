// shanshen.c ��ɽ��

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("��ɽ��", ({"laoshan shen", "shen"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��մ��ɽ��ĳ�����ɽ�Ρ�\n");
		set("value", 10000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	this_player()->receive_curing("qi", 20);

	message_vision("$N����һ����ɽ�Σ�ֻ���û���һ����������ð������ !\n", this_player());
	destruct(this_object());
	return 1;
}


