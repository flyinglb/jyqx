//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","山路");
	set("long", @LONG
自棋盘坳走向这边的路又有不同风景，细长的山路两旁是低矮的只有西北
高寒地带才有的灌木。
LONG );
	set("exits", ([
		"northwest"  : __DIR__"houshan2",
		"south" : __DIR__"qipan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

