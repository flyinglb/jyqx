// book1.c

inherit ITEM;

void create()
{
	set_name("��������", ({ "parry book", "book" }));
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������С�ᣬ���������໥��򶷵�����\n");
		set("value", 50);
		set("material", "paper");
		set("skill", ([
			"name":	"parry",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	20,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	50	// the maximum level you can learn
		]) );
	}
}

void init()
{
	if( this_player() == environment() )
		add_action("do_study", "study");
}

int do_study(string arg)
{
	object me = this_player();

	if ( arg != "parry book" )
	return notify_fail("��Ҫѧʲô��\n");

	if ( me->is_fighting() 
	&& (int)me->query_skill("parry", 1) >= 80 
	&& (int)me->query_skill("parry", 1) <= 200 )
	{
		me->receive_damage("jing", 20);
		me->improve_skill("parry", me->query("int")*2);
		message_vision("$Nһ��ս����һ�߳�ռ���ææ���ó�����������ϸ�о���\n", me);
		return 1;
	}

	return 0;
}
