//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","洞室");
	set("long", @LONG
在地洞的尽头有这么一处更加宽敞的所在，里面有石桌石凳石床石箱，还
堆积了很多瓦罐，里面看来是清水。这地方看起来是有人为了避难做好的藏身
之地。在靠墙的石坑里燃了一支儿臂粗的长明蜡烛，让人可以很清楚地看清楚
洞里的情况。
LONG );
	set("exits", ([
		"east"  : __DIR__"dong4",
	]));
	set("objects", ([
		__DIR__"npc/yaoqingquan" :1,
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

