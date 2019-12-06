//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","山田");
	set("long", @LONG
这是一片在山坡向阳面上开垦出的农田，经昆仑派弟子数十年经营，在几
十亩的山坡上也初据规模。这里有大麦、高粱、玉米以及十多种蔬菜曾种植的
痕迹。
LONG );
	set("exits", ([
		"east" :  __DIR__"shantian1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}
//这里做昆仑弟子耕田任务的执行地点

