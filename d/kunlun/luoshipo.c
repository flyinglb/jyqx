//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","乱石坡");
	set("long", @LONG
这里除了能明显看清楚两条细小的肯定可以走的山路外，好象还有一条可
以攀缘而上的路，据说有人从这里上去曾经采到过灵芝，而另外有人说这上面
通向一个吃人恶魔的洞窟。
LONG );
	set("exits", ([
		"south" :  __DIR__"xxroad3",
		"eastdown"  :  __DIR__"houshan4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

