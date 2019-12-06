// Pill: sanxiaosan.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("��Ц��ңɢ", ({"sanxiaoxiaoyao san", "xiaoyao san", "san"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����ɫ�ķ�ĩ, �����Ӳ���Ѱ����Ʒ. \n");
		set("unit", "��");
		set("pour_type", "sanxiao_poison");
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
	if(arg=="san" || arg=="xiaoyao san")
	{
		message_vision("$N��ͷ����һ��" + name() + "��\n", me);
		this_player()->die();
		destruct(this_object());
	}
	return 1;
}
