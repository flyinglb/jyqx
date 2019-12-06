//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","山林");
	set("long", @LONG
转过了白象山，山势好象缓了很多，山林也渐渐疏松，白雪覆盖的地方好
象也少了，远远看去，可以看到一些灰黄土石的山丘。
LONG );
	set("exits", ([
		"southeast"  : __DIR__"baixiang",
		"northwest"  : __DIR__"shalu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

