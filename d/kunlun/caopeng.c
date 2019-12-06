//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","草棚");
	set("long", @LONG
一个很简陋的草棚，也不知道是什么人在这里搭的，棚子四周居然还用草
席围了起来。在草棚里，有一个木板搭起的架子，上面铺了软草，看来人可以
在上面休息一下的。草棚搭在山脉的凹处，树林又密，看样子很挡风。
LONG );
	set("exits", ([
		"south"      : __DIR__"cunlu2",
	]));
	set("no_clean_up", 0);
	set("sleep_room", 1);
	setup();
	replace_program(ROOM);
}

