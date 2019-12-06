//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","走廊");
	set("long", @LONG
这是铁琴居内部的一个走廊。
LONG );
	set("exits", ([
		"south" :  __DIR__"tieqin",
		"east" :  __DIR__"chufang",
		"north" :  __DIR__"houhuayuan",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/binv" : 1,
	]));
	setup();
	replace_program(ROOM);
}

