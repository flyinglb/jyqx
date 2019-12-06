//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","雪岭云杉林");
	set("long", @LONG
路就在这山与山之间的杉林中曲折，林中间或会跳出一只猴子或松鼠。但
路的前方却看不清楚，脚下的路多是积雪和草丛中拓开的小径。
LONG );
	set("exits", ([
		"northwest"  : __DIR__"songlin3",
		"east"  : __DIR__"songlin1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

