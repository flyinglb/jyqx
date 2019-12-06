//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","谷场");
	set("long", @LONG
在小路的中间有一处地势略高的开阔地，这里一直积雪不化。在场地中间
有一个很大的谷堆，足有三四人高，谷堆上也积满了冰雪。从这里抬头望去，
一座笔直的山峰直插云霄，看不到高处的情况。从这谷场的东西两面都是崎岖
的小路。
LONG );
	set("exits", ([
		"east"  : __DIR__"cunlu3",
		"west"  : __DIR__"cunlu4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}
