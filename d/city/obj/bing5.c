//bing5.c ���ñ�
inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(YEL "���ñ�" NOR, ({"bing5", "duitangbing"}));
	set("unit", "��");
	set("no_get", 1);
/*
	set("no_drop", 1);
	set("no_put", 1);
	set("no_beg", 1);
	set("no_steal", 1);
*/
	set("long", "����һ���ѳ��Ķ��ñ���\n");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if(arg=="bing5"||arg=="duitangbing")
	{
		me->add("combat_exp",868);
		me->add("potential",68);
		me->add("con",1);
		me->add("dex",1);
		message_vision(HIY "$N�������ڳ���һ��$n��\n" NOR, this_player(), this_object());
		destruct(this_object());
	}
	return 1;
}
void owner_is_killed()
{
        destruct(this_object());
}
