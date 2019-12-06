//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","山脊路");
	set("long", @LONG
跨过一个山峰，村庄已在你的眼前，脚下这条路也踏入了两山之间，适才
望着悬崖胆战心惊的感觉已然荡然无存，取而代之的是这面前青天白云之下、
素雪翠岭之间的村庄。村庄的吸引力太大了，你抛开一路的疲惫快步向西走去。
LONG );
	set("exits", ([
		"east"  : __DIR__"jilu2",
		"west"  : __DIR__"zhuwu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

