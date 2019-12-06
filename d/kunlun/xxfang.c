//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","西厢房");
	set("long", @LONG
屋里堆积了很多杂物。几只破旧的木桌在屋里划出一条可以走人的路来，
屋子后面还有一个门，好象通向一个侧面的院子。
LONG );
	set("exits", ([
		"east"  : __DIR__"beiyuan",
		"west"  : __DIR__"laying",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

