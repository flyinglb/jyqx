// pill.c

inherit COMBINED_ITEM;

void setup()
{
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
//        string what = query("cure");
//        int howmuch = query("amount");

	if (!id(arg))
		return notify_fail("�����ʲô��\n");

	if ((int)this_player()->query("eff_qi") == 
	    (int)this_player()->query("max_qi"))
		return notify_fail("�����ڲ���Ҫ��" + this_object()->name() + "��\n");
	else {
		this_player()->receive_curing("qi", 50);
		message_vision("$N����һ����ҩ����ɫ�������ö��ˡ�\n", this_player());
		destruct(this_object());
		return 1;
	}
}

