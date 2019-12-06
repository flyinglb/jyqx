//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","昆仑山路");
	set("long", @LONG
一眼望去，还是无尽的高山，山上已多了许多树木，有低矮的灌木，也有
高大的松柏，山势也越发险峻，许多高山都在云雾之中了，而脚下也有飘渺若
青烟般的云雾，真叫人分不清是在天上还是在人间了。
LONG );
	set("exits", ([
		"westup"  : __DIR__"shanlu5",
		"eastdown"  : __DIR__"shanlu1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

