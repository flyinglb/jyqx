#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("�ۻ�", ({"xionghuang" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���ۻ�,��˵�����ٶ���\n");
		set("value", 1000);
	}
	setup();
}

int do_eat(string arg)
{
	return notify_fail("���������ۻƲ��ܳ�.\n");
}

