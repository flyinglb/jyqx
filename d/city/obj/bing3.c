//bing3.c �Ľ���
inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIG "�Ľ���" NOR, ({"bing3", "sijingbing"}));
	set("unit", "��");
	set("long", "����һ��Ũ����Ľ�����\n");
/*
	set("no_get", 1);
	set("no_drop", 1);
	set("no_put", 1);
	set("no_beg", 1);
	set("no_steal", 1);
*/
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if(arg=="bing3"||arg=="sijingbing")
	{
		me->add("combat_exp",468);
		me->add("potential",8);
		message_vision(HIY "$N�������ڳ���һ��$n��\n" NOR, this_player(), this_object());
		destruct(this_object());
	}
	return 1;
}
void owner_is_killed()
{
        destruct(this_object());
}
