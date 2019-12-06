//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","乡村路");
	set("long", @LONG
小路的一面是深不可测的林海，一面是高不见顶的山峦，山和林与路一起
曲曲弯弯通向远方。而前面，好象有一个小山村，这在万里昆仑山，能见到人
影已经是很难得了，何况看到一座村子。
LONG );
	set("exits", ([
		"east"       : __DIR__"guchang",
		"northwest"  : __DIR__"xiaocun",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

