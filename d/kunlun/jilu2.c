//Robin 200.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","山脊路");
	set("long", @LONG
就在这跨越着山峰的山路的一处山梁上，居然还有一条小路通向北面一座
更高的山峰。那里的山顶又隐没在更高的云层里了，而山下面的情况更是无法
看得清楚。
LONG );
	set("exits", ([
		"northup"  : __DIR__"xuanya",
		"east"  : __DIR__"jilu1",
		"west" :  __DIR__"jilu3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

