// Pill: bicanfeng.c


inherit ITEM;

void create()
{
	set_name(GRN"�̲Ϸ�"NOR, ({"bican feng", "feng"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���綾�Ķ�ҩ, ��������������м�Ѫ���֮Ч. \n");
		set("unit", "��");
		set("value", 20000);
	}
	setup();
}

int init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");
	if(arg=="feng" || arg=="bican feng") 
	{
		message_vision("$N��ͷ��һС��" + name() + "��������ȥ��\n", me);
		me->die();
		destruct(this_object());
	}
	return 1;
}
