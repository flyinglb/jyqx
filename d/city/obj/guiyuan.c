// guiyuan.c ��Ԫ��

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("��Ԫ��", ({"guiyuan dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��Ө����Բ�Ĺ�Ԫ����\n");
		set("value", 10000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	this_player()->add("neili", 200);
	message_vision("$N����һ�Ź�Ԫ����ֻ������֫�ٺ�������ӯ�ޱ� !\n", this_player());
	destruct(this_object());
	return 1;
}


