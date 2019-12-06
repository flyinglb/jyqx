//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","山路");
	set("long", @LONG
再望去这山路的两侧已看不清山峰了，高耸入云的云杉和青松遮住了路人
的视野，而山路也更象一条林间小径。
LONG );
	set("exits", ([
		"westup"  : __DIR__"luoshipo",
		"southeast" :  __DIR__"houshan2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

