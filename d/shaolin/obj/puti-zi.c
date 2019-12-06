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
		set("value", 500000);
	}
	setup();
}

int do_eat(string arg)
{
//        int force_limit, neili_limit, force_skill, add_skill, improve;
        int force_limit, neili_limit, force_skill;

	object me = this_player();

	force_limit = me->query_skill("force")*10;
	neili_limit = me->query("max_neili");
	force_skill = me->query_skill("force", 1);
	
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

        if( me->is_busy() )
                return notify_fail("��Ķ�����û����ɣ����ܳԶ�����\n");


	if ( (int)me->query_condition("putizi_drug" ) > 0 )
	{
		me->add("max_neili", -100);
		if ((int)me->query("max_neili")<0) me->set("max_neili",0) ;
		message_vision(HIR "$N�ֳ���һ�������ӣ�ֻ���øγ���ϣ��������ѣ�ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
	else if ( neili_limit <= force_limit  )
	{
/*		improve = force_limit - neili_limit;

		if ( improve < 100 ) { 
			add_skill = force_skill + (100 - improve)/5 + 1;
			me->set_skill("force", add_skill );
		}
*/	
		me->add("max_neili", 100);
		me->add("neili", 100);

		message_vision(HIY "$N����һ�������ӣ���Ȼ��ֻ��һ�ɺƵ��ޱȵ�����ֱ�嶥��...\n" NOR, this_player());
		me->apply_condition("putizi_drug", 1000);
	}
	me->start_busy(100);
//	me->unconcious();
	destruct(this_object());
	return 1;
}

