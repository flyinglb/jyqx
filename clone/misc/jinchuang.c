// jinchuang.c ��ҩ

inherit ITEM;


void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIY"��ҩ"NOR, ({"jinchuang yao", "jinchuang", "yao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������ʿ�ر��Ľ�ҩ��\n");
		set("value", 5000);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	if (!id(arg))
		return notify_fail("��Ҫ��ʲôҩ��\n");
	if (me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
	if ((int)me->query("eff_qi") == (int)me->query("max_qi"))
		return notify_fail("�����ڲ���Ҫ�ý�ҩ��\n");
	else {
		me->receive_curing("qi", 50);
		message_vision("$N����һ����ҩ����ɫ�������ö��ˡ�\n", me);
		me->start_busy(2);
		destruct(this_object());
		return 1;
	}
}

