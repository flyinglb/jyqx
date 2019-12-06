//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","小村");
	set("long", @LONG
所谓村子就是在一个空旷的地方多了几间房屋，房屋的门口多悬挂了一些
兽皮弓箭，看来这里的人都是以打猎为生的。村子里能见到的人很少，只有一
个猎户装束的汉子倚在门前看着远来的你，在他的手中拿了一支干枯的灵芝。
你心里一动，“人说昆仑山上有灵芝，难道这猎户是采灵芝的？”
LONG );
	set("exits", ([
		"southeast"  : __DIR__"cunlu4",
		"westdown"  : __DIR__"shanlin1",
	]));
	set("objects", ([
		__DIR__"npc/liehu" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

