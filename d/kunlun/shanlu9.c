//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","昆仑山路");
	set("long", @LONG
路在山腰上，一面是看不到顶的高山，一面是望不到底的深谷，走在这样
的路上，你实在是无法再欣赏这山与云的风景了。就在这两山之间，还有一条
通向北面的小路。
LONG );
	set("exits", ([
		"east"  : __DIR__"shanlu8",
		"northwest"  : __DIR__"shanlu10",
		"north" : __DIR__"xxroad1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

