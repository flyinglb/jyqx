// Room: /huanghe/shamo1.c
// Java. Sep 21 1998

#include <room.h>
#include <ansi.h>

inherit ROOM;
void create()
{
	set("short", "ɳĮ");
	set("long", @LONG
����һƬû�߼ʵ�ɳĮ�������ǽ����׸ߵľ޴�ɳ����һ�߽���
�ͷ·�����·�������и�ʯ����
LONG );
	set("exits", ([
		"north" : __DIR__"shamo",
		"south" : __DIR__"shamo",
		"east"  : __DIR__"shamo",
		"west"  : __DIR__"shamo",
		"enter" : __DIR__"shidong",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	setup();
}
void init()
{
	object ob = this_player();
	if (ob->query("water") > 10)
		ob->set("water", ob->query("water") -10 );
	else
		ob->set("water", 0 );
	message_vision(HIY"�����ɳ��$N�е�����ð�̣��ɿ��Ѱ���\n"NOR, ob);
}

int valid_leave(object me, string dir)
{
	int total_steps = random(9)+1;
	if ( dir == "north")
		me->add_temp("shamo/steps",1);
	if ( dir == "south")
		me->add_temp("shamo/steps",-1);
	if (me->query_temp("shamo/steps") == total_steps)
	{
		me->move(__DIR__"jingyuan");
		me->delete_temp("shamo/steps");
		return notify_fail("�����˰��죬�����߳�������ɳĮ��\n");
	}
	if (me->query_temp("shamo/steps") == - total_steps )
	{
		me->move(__DIR__"qingcheng");
		me->delete_temp("shamo/steps");
		return notify_fail("�����˰��죬�����߳�������ɳĮ��\n");
     	}
	return ::valid_leave(me,dir);
}

