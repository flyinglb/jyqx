// gaoyao.c

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_tie", "tie");
}

void create()
{
	set_name("��Ƥ��ҩ", ({"goupi gaoyao", "goupi", "gaoyao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������ʿ����(tie)�Ĺ�Ƥ��ҩ��\n");
		set("value", 5000);
	}
	setup();
}

int do_tie(string arg)
{
	object me = this_player();
	if (!id(arg))
		return notify_fail("��Ҫ��ʲôҩ��\n");
	if (me->is_busy() )
		return notify_fail("������û������Ƥ��ҩ�ˡ�\n");
	if ((int)me->query("eff_qi") == (int)me->query("max_qi"))
		return notify_fail("�����ڲ���Ҫ�ù�Ƥ��ҩ��\n");
	else {
		me->receive_curing("qi", 50);
		message_vision("$Nž��һ�����˿�������һ����Ƥ��ҩ����ɫ�������ö��ˡ�\n", me);
		me->start_busy(2);
		destruct(this_object());
		return 1;
	}
}

