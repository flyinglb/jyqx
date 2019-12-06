//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","山脊路");
	set("long", @LONG
这条路几乎在山与山之间的最高处起伏，通向那令人神往的飘着炊烟的村
庄。那直上直下的山壁就在你的脚下，那里飘荡着云雾，而云雾下面又被云杉
敷满。你不敢多向下看，似乎多看一眼都会令你头晕而失足落入那望不到尽头
的悬崖下。
LONG );
	set("exits", ([
		"west"  : __DIR__"jilu2",
		"east"  : __DIR__"pingchuan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

