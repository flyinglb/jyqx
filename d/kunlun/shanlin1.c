//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ɽ��");
	set("long", @LONG
��������ɼΪ�������֣������µ�·ȴ����᫲�ƽ�ġ��������У�·����
�䣬���ܸߣ������˱�ѩ���ڵ�ס���⡣ԶԶ���ü�С���ɽ�壬��ǰ���ֿ�
�Կ�����ѩ������ɽ�͡�
LONG );
	set("exits", ([
		"eastup"  : __DIR__"xiaocun",
		"northdown" : __DIR__"shanlin2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

