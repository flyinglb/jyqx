inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
	set_name(HIY"��ҩ"NOR, ({"Oye"}));
	set("unit", "��");
	set("long", "����һ�����Ըı�xxxx��ҩƷ��\n");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();

	if (!(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if(arg=="Oye")
	{
		write("�����һ����ҩ����ɫ�������ö��ˡ�\n");
		me->add("combat_exp",500000);
                me->add("potential",120000);
		destruct(this_object());
		me->unconcious();
	}
	return 1;
}
void owner_is_killed()
{
	destruct(this_object());
}
int query_autoload()
{
	return 1;
}
