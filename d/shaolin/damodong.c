// Room: /d/shaolin/damodong.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "��Ħ��");
	set("long", @LONG
�����Ǵ�Ħ�Ŷ��������ǰ������ɮ�������Ħ���������£���
�˷�ˮ���أ���ס�������޵��ӣ��������ڣ����������·������ǧ
�겻��֮������Ħ��ʦ���ڴ���������һ��ʮ�꣬�ڼ��������Կ�
���������ʱ�Ĵ�����̬�������ϵļ�����Ƭ�⣬���п���һ�
LONG );
	set("exits", ([
		"out" : __DIR__"bamboo1",
	]));
	set("objects",([
		"/clone/book/book-bamboo" : 1,
		CLASS_D("shaolin")+"/da-mo" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
}

void init()
{
	object me = this_player();

	if ((int)me->query_temp("bamboo/count") == 14 
	&&  (int)me->query_skill("dodge", 1) >= 30 
	&&  (int)me->query_skill("dodge", 1) <= 100 
	&&  present("bamboo", me) )
	{
		me->receive_damage("jing", 20);
		me->improve_skill("dodge", me->query("int"));
	}

        add_action("do_mianbi","���");	
        add_action("do_mianbi","mianbi");	
}

int do_mianbi()
{
	object me = this_player();

	message_vision("$N����Ŵ�Ħ�����ߵ�ʯ�ڵ�����˼�����ã���������\n", me);
	
	me->set_busy(10);
	me->set("shen",0);

	return 1;
}
