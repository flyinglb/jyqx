#include <ansi.h>

inherit ITEM;


void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIY "��֥" NOR, ({"lingzhi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
		set("long", "����һ֧��������ɽ�ϵ���֥��\n");
		set("value", 50000);
	}
	setup();
}

int do_eat(string arg)
{
	int force_limit, neili_limit ;
	object me = this_player();
	force_limit = me->query_skill("force")*10;
	neili_limit = me->query("max_neili");
	if (!id(arg)||(arg!="lingzhi"))
	return notify_fail("��Ҫ��ʲô��\n");

	if ( neili_limit <= force_limit  )
	{
		me->add("max_neili",10);
		me->add("neili",10);
		message_vision(HIY "$N����һ֧��֥����Ȼ��ֻ��һ������֮��ֱ���ķ�...\n" NOR, this_player());
	}
	else
		message_vision(HIY "$N����һ֧��֥�����Ǻ���ûʲô��.\n" NOR, this_player());

	destruct(this_object());
	return 1;
}

