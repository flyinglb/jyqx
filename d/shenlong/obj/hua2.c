// hua2.c ������
inherit ITEM;

//void init()
//{
//	add_action("do_eat", "eat");
//}

void create()
{
	set_name("������", ({"hua2", "wuming"}));
	set("unit", "��");
	set("long", "����һ������С����������С��ȴʮ��������\n");
	setup();
}

int do_eat(string arg)
{
//        object me=this_player();
	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if(arg=="hua2")
	{
//		me->add("max_neili",5);
//		me->unconcious();
		destruct(this_object());
	}
	return 1;
}
