inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
	set_name(HIW"�츳��"NOR, ({"tianfu gao","gao"}));
	set_weight(3000);
	set("unit", "��");
	set("long", "����һ����Ըı��츳��ҩƷ��\n");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();

	if (!(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if(arg=="gao")
	{
		write(HIC"�������һ���츳�ֻ࣬�������巢����һЩ�仯��\n"NOR);
		me->add("combat_exp",150000);
		me->add("potential",30000);
//		me->add("max_neili",60000);
//		me->add("neili",60000);
//              me->add("score",2000);
//              me->add("mud_age",43200);
//		me->add("per",13);
//		me->add("kar",17);
		destruct(this_object());
		me->unconcious();
	}
	return 1;
}
