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
		"southup"   : __DIR__"shanlin1",
		"northwest" : __DIR__"baixiang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

