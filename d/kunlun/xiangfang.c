//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","厢房");
	set("long", @LONG
这里是武庄仆役居住的房子，有几个没事的仆役正在赌钱，根本不会注意
有什么人走进来。
LONG );
	set("exits", ([
		"west"  : __DIR__"nanyuan",
	]));
	set("objects", ([
		__DIR__"npc/jiading" : 3,
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

