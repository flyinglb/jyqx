//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","山间平川");
	set("long", @LONG
这是一个山与山之间的平地，正好是从那数十丈陡坡走上来后可以休息一
下的地方。从这里远眺，群山笼罩在白雪与白云之间，在那洁白的云与雪的下
面是青青翠绿的山林。而那山，那林，那云，那雪都在前方一种景象下黯然失
色了，因为那是一个村庄，一个飘着炊烟的村庄，对一个行走千里看不到人烟
的旅人来说，那炊烟有着巨大的吸引力。
LONG );
	set("exits", ([
		"west"  : __DIR__"jilu1",
		"northdown"  : __DIR__"doupo",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

