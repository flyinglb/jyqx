//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","小路");
	set("long", @LONG
路势渐渐平缓，路旁的山坡上有些山菇草菌，由于在山的北面，山坡上的
树木遮住了早晚的阳光，这小路就显得有一些阴森。
LONG );
	set("exits", ([
		"south" :  __DIR__"xxroad1",
		"north" :  __DIR__"xxroad3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

