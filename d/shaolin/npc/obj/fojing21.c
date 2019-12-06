// fojing21.c

inherit ITEM;

string* titles = ({
//	"������",
//	"άĦ��",
//	"������",
//	"���Ͼ�",
	"�����پ�",
	"������;�",
	"������",
	"��վ�",
	"�����۶��ľ�",
});

void create()
{
	set_name(titles[random(sizeof(titles))], ({ "shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��𾭡�\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"buddhism",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	20,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	100	// the maximum level you can learn
		]) );
	}
}


void init()
{
	if( this_player() == environment() )
	{
		add_action("do_tear", "tear");
	}
}

int do_tear(string arg)
{
	object me, bible;
	object where;

	if ( !arg )
	{
		return notify_fail("ʲô��\n");
	}

	me = this_player();

	if ( arg == "jing" || arg == "shu" || arg == "book" )
	{
		bible = new(CLASS_D("shaolin")+"/obj/book-jiuyang");
		where = environment(me);
		message_vision("$N����ذ���˺��������ͻȻ�������Ʈ�����ҳ��Ƥֽ��\n",
			this_player());
		bible->move(file_name(where));
		destruct(this_object());
	}

	return 1;
}
