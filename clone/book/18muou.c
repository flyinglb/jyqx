// 18muou.c

inherit ITEM;

void create()
{
	set_name("ʮ��ľż", ({ "18 muou", "muou" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", 
"����һ��Сľ�У����е����޻�������������ľż�������ϲ
�ò�������ʹ�����ᣬ�������ŭ����ȺͿ��ף���һ��ͬ��\n");
		set("value", 5000);
		set("material", "wood");
		set("skill", ([
			"name":	      "force",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	40,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	99,	// the maximum level you can learn
			"min_skill":	60	// the maximum level you can learn
		]) );
	}
}

/*
void init()
{
	if( this_player() == environment() )
	{
		add_action("do_nie", "nie");
	}
}

int do_nie(string arg)
{
	object me, muou;
	object where;

	if ( !arg )
	{
		return notify_fail("ʲô��\n");
	}

	me = this_player();

	if ( arg == "niou" )
	{
                muou = new(__DIR__"18muou");
		where = environment(me);
		message_vision(
"$N����һ��ˢˢˢ������������������ķ��Ρ��Ͳʺ����
�׷׵��䡣$Nһ������Ӵ�����ĸп�ϧ��ȴ��������䴦����
����һ�������ľ�档�����ٽ���۰���һЩ��������ϡ�ֳ�
���Σ����½�����������۾�����ȥ��¶��һ�������ľż����
ľż��������һ��ͩ�ͣ������˺��ߣ�ȴ��Ѩ��λ�á�ľż��
�����ɣ���Ŀ������������������Ц֮״��˫����������̬��
��֮������ò�ͱ��������˽�Ȼ��ͬ��\n", this_player());
		muou->move(file_name(where));
		destruct(this_object());
	}

	return 1;
}
*/
