//hua.c ���㻨
inherit ITEM;
#include <ansi.h>

//void init()
//{
//	add_action("do_eat", "eat");
//}

void create()
{
	set_name(HIG"���㻨"NOR, ({"hua", "baixiang"}));
	set("unit", "��");
	set("long", "����һ�����޵Ļ�������Ũ���쳣��\n");
	setup();
}

int do_eat(string arg)
{
//        object me=this_player();
	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if(arg=="hua")
	{
//		me->add("max_neili",5);
//		me->unconcious();
		destruct(this_object());
	}
	return 1;
}

