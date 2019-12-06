//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","小路");
	set("long", @LONG
这条小路通向山高崖远处，也不再有一旁深谷的凶险，只是路的走势却是
忽高忽低，路的两侧有一些凌乱的草木。
LONG );
	set("exits", ([
		"south" :  __DIR__"shanlu9",
		"north" :  __DIR__"xxroad2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

