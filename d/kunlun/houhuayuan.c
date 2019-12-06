//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","后花园");
	set("long", @LONG
这里是掌门人家内宅中的一个花园，园中种了一些希奇古怪的花草。花园
的几个门分别通向何太冲的几个夫人的住处。
LONG );
	set("exits", ([
		"south" :  __DIR__"zoulang1",
		"north" :  __DIR__"zhengfang",
		"west"  :  __DIR__"cefang",
	]));
	set("objects", ([
		__DIR__"npc/binv" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors","kunlun");
	setup();
	replace_program(ROOM);
}

