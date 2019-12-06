// Room: /d/shaolin/dxbdian.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "���۱���");
	set("long", @LONG
�����������µĴ��۱�����й������������������Ҹ���
���⡢����������һȺ����С���������ڷ���ǰ�ĵ����о���
�����������󳪽�����һ�����ӷ����黨ǳЦ�����ݣ����˶�
ʱ���𼸷�����֮�С���߾�����һ�Ӷ�ɮ�������룬������
�ֳֽ䵶���ƺ���Ѳ�µ�ɮ�ˡ�
LONG );
	set("exits", ([
		"southdown" : __DIR__"guangchang2",
	]));
	set("valid_startroom",1);
	set("book_count",1);
	set("objects",([
		CLASS_D("shaolin") + "/dao-zheng" : 1,
		__DIR__"npc/xiang-ke" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	"/clone/board/bonze_b"->foo();
}

void init()
{
	this_player()->set_temp("ketou_times", 50);
	add_action("do_ketou", "ketou");
}

int do_ketou()
{
	object me, ob;

	me = this_player();
		
	if ( me->query_temp("ketou_times") == 0 )
	{
		message_vision("$N��ͷ�ĵ����˹�ȥ��\n", me);
		me->set_temp("ketou_times", random(50));
		me->unconcious();
		return 1;
	}

	me->add_temp("ketou_times", -1);	

	message_vision("$N�ϵع�������������������ǰ��ͷ��\n", me);

	if ( random(100) == 37 
	&& !present("silk", me)
	&& query("book_count") >= 1)
	{
		add("book_count", -1);
		ob=new("/clone/book/book-silk");
		ob->move("/d/shaolin/dxbdian");
		tell_object(me, "ͻȻ����ǰ��ž��һ������һ����Ƥ�ߴ������ı��\n");
	}

	if ((int)me->query_skill("force", 1) >= 30 
	&& (int)me->query_skill("force", 1) <= 100 
	&& present("silk", me) )
	{
		me->receive_damage("jing", 20);
		me->improve_skill("force", me->query("int"));
		if ( random(5) == 0 )
		tell_object(me, "ڤڤ֮�У����ƺ����÷����ڵ㲦�����ڹ���������ѡ�\n");
	}
	return 1;

}

int valid_leave(object me, string dir)
{
	if(me->query_temp("ketou_times") >= 0 ) me->delete_temp("ketou_times");

	return ::valid_leave();
}

