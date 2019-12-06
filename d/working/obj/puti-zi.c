// puti-zi.c ������

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
	set_name("������", ({"puti zi", "zi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ž�Ө����������ӣ�������ɽ������ǰ����ϡ�ޱȣ�
������������֮ʵ�����ܻ��ٽ٣���ǧ�֣������ͬ�١�\n");
		set("value", 1000000);
	}
	setup();
}

int do_eat(string arg)
{
	int force_limit, neili_limit, force_skill, add_skill, improve;

	force_limit = (int)this_player()->query_skill("force")*10;
	neili_limit = (int)this_player()->query("max_neili");
	force_skill = (int)this_player()->query_skill("force", 1);
	
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
//39
	if ( neili_limit <= force_limit  )
	{
		improve = force_limit - neili_limit;

		if ( improve < 100 )
		{ 
			add_skill = force_skill + (100 - improve)/5 + 1;
			this_player()->set_skill("force", add_skill );
		}
	}
	
	this_player()->add("max_neili", 100);
	this_player()->add("neili", 100);

	message_vision(HIY "$N����һ�������ӣ���Ȼ��ֻ��һ�ɺƵ��ޱȵ�����ֱ�嶥��...\n" NOR, this_player());
	this_player()->unconcious();
	destruct(this_object());
	return 1;
}

