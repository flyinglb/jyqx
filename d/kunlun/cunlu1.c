//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","乡村路");
	set("long", @LONG
这是一条盘延在昆仑山之间的小路，两面是白皑皑的崇山峻岭，山顶都伸
到了云里，看不出到底有多高。山下是松、柏、杉组合的山林，而这小路就在
这林中延伸，看来前面应该有什么所在。
LONG );
	set("exits", ([
		"east"  : __DIR__"songlin3",
		"northwest"  : __DIR__"cunlu2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

