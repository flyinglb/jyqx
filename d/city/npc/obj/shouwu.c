// shouwu.c ������

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("������", ({"heshou wu", "wu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ó������εĺ����ڡ�\n");
		set("value", 10000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

        if(arg != "wu" && arg != "heshou wu") return 0;
        if( this_player()->query("max_jingli") > 5999 ) {
                message_vision("$N����һ�ú����ڣ������ƺ�ûʲô���á�\n", this_player());
        } else {
		this_player()->add("max_jingli", 2);
		this_player()->set("eff_qi", this_player()->query("max_qi"));
		message_vision("$N����һ�ú����ڣ���ʱ�����ȫ������˻��� !\n", this_player());
	}
        move(VOID_OB);
        destruct(this_object());
	return 1;
}

