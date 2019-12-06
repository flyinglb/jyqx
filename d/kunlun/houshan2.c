//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","山路");
	set("long", @LONG
山路两边的低矮灌木已夹杂了昆仑高处所特有的雪岭云杉，两侧望去的高
山上已经可以见到那终年不化的积雪了。路旁有个短短岔路通向一个山神庙。
LONG );
	set("exits", ([
		"northwest" : __DIR__"houshan4",
		"southeast" : __DIR__"houshan1",
		"east"  : __DIR__"houshan3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

