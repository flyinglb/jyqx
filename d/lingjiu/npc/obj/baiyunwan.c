// baiyunwan.c �����ܵ���

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("�����ܵ���", ({"baiyunxiudan wan", "wan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������ʿ�������������ʥҩ��\n");
		set("value", 50000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");
	this_player()->receive_curing("qi", 100);
	this_player()->receive_curing("jing", 100);
	message_vision("$N����һ�Ű����ܵ��裬ֻ��������������ɫ��á�\n", this_player());
	destruct(this_object());
	return 1;
	
}

