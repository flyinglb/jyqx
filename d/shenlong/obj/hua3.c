inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
	set_name(HIR "�ϳ���" NOR, ({"hua3","duanchang"}));
        set("unit", "��");
	set("long", "����һ��ϳ���,ͨ��ͨ��,��������,�����쳣��\n");
        set("no_get", "��������ҽ�ǰ.\n");
        setup();
}

int do_eat(string arg)
{
	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if(arg=="hua3") 
	{
		if(random(2)==0) this_player()->unconcious();
		else this_player()->die();
		destruct(this_object());
	}
	return 1;
}
