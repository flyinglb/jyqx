//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","后花园");
	set("long", @LONG
花园里的花并不多，人工的山石却是不少，园中道路曲折，让这不大的花
园显得此起彼伏，甚是有致。在花园的西南边是这花园最大的一个假山，绕过
那假山露出回廊的一角。
LONG );
	set("exits", ([
		"southwest" : __DIR__"jiashan",
		"southeast" : __DIR__"neiyuan1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

