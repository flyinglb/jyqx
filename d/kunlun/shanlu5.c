//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","昆仑山路");
	set("long", @LONG
望不尽的插云高山，飘不完的绕山白云，山顶终年不化的积雪，让人分不
清是云还是雪。山和云之间便是昆仑山上特有的雪岭云杉林。林如云一般密，
无始无终；树若山一般高，高不可攀。脚下的这路就在这山与林之间迤俪，看
不到终点通往哪里。
LONG );
	set("exits", ([
		"westup"  : __DIR__"shanlu6",
		"eastdown"  : __DIR__"shanlu4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

