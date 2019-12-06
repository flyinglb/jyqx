//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","昆仑山路");
	set("long", @LONG
在这窄窄的山道上，这里应该是地势最低的地方了，南面是一片灌木和低
矮松柏组合而成的密林，白天的阳光可以完全照射到这条山路上，这在昆仑山
的这条路上是难得一见的。北面是一片无数鲜花绿叶簇成的山坳，那里是武林
中昆仑派的所在。
LONG );
	set("exits", ([
		"northdown": __DIR__"sansheng",
		"east"  : __DIR__"shanlu6",
		"west"  : __DIR__"shanlu8",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

