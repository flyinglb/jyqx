// 18niou.c

inherit ITEM;

void create()
{
	set_name("ʮ����ż", ({ "18 niou", "niou" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", 
"����һ��Сľ�У����е����޻�������������������ż��ÿ����
��������һʮ�˸�����ż�������ɣ�ÿ��������������ˣ�Ƥ��
��Ϳ�˰��ѣ�������һ�������ߣ����������ڵ㣬���������Ѩ
���ķ�λ��\n");
		set("value", 5000);
                set("no_sell", 1);
		set("material", "mud");
		set("skill", ([
			"name":	      "force",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	30,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	59,	// the maximum level you can learn
			"min_skill":	30	// the maximum level you can learn
		]) );
	}
}

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
