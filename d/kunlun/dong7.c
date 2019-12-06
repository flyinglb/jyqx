//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","地洞");
	set("long", @LONG
一个深深的地洞，深得看不清有多深，但洞里并不狭窄，远远看到有些烛
光在跳跃，在这黑黑的洞里显得特别显眼。可以看到洞里并不潮湿，也没有一
点脏乱，看来有人经常来打扫。
LONG );
	set("exits", ([
		"south" : __DIR__"dong6",
		"east"  : __DIR__"dong8",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

