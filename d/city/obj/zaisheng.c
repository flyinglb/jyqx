// lianzi.c ������

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("������", ({"bailian zi", "zi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ž������������衣\n");
		set("value", 2000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("��Ҫ��ʲôҩ��\n");

	if (((int)this_player()->query("potential") - 100) >=
	     (int)this_player()->query("learned_points") )
		return notify_fail("�����ڲ���Ҫ�������衣\n");
	else {
	        this_player()->add("potential", 1);
	        message_vision("$N����һ�������裬�е������������һ��΢��ı仯 !\n", this_player());
	        destruct(this_object());
	        return 1;
	}
}

