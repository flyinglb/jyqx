//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","沙路");
	set("long", @LONG
脚下的路似乎炎热了起来，不再看见冰雪的景象，入眼却多了很多风沙。
东北一条山路，通向一座怪石与黄沙堆积而成的山峰。而前方的路也布满无尽
的尘沙，让天地也融化在那尘沙中了。
LONG );
	set("exits", ([
		"southeast"  : __DIR__"shanlin3",
                  "west"  : "/d/gaochang/room63",
//		"northeast"  : "/map/mingjiao/xishan1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

