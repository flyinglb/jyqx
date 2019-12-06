//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","昆仑山路");
	set("long", @LONG
转过一座山头，昆仑山的山势又有了变化，山越来越高，甚至是高山上再
起山头，山上的树木也少了，而脚下的这条路已不仅绕在山与山之间，逐渐盘
到山腰上了。
LONG );
	set("exits", ([
		"east"  : __DIR__"shanlu7",
		"west"  : __DIR__"shanlu9",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

