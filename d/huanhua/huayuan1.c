// huayuan1.c

inherit ROOM;

void create()
{
	set("short", "花园");
	set("long", @LONG
来到这里，你感到眼前一亮，想不到这里竟有这么一处所在，各种花朵竟相开
放，一派春意盎然的景象。走在花从之中，你感到陶醉了。
LONG
	);
        set("exits", ([ 
		"south" : __DIR__"liangong2",
		"east" : __DIR__"liangong1",
		"west" : __DIR__"dating",
		"north" : __DIR__"liangong3",
]));
	setup();
	replace_program(ROOM);
}
