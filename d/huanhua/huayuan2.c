// huayuan2.c

inherit ROOM;

void create()
{
	set("short", "花园");
	set("long", @LONG
来到这里，你不由心情舒畅，花园中间有一座假山，上面居然还有潺潺流水，
真是巧夺天工，小路两旁各种花朵竟相开放，争奇斗艳，走在这花径之中，你
的步伐也慢了。
LONG
	);
        set("exits", ([ 
		"east" : __DIR__"dating", 
		"south" : __DIR__"liangong4",
		"west" : __DIR__"liangong5",
		"north" : __DIR__"liangong6",
]));
	setup();
	replace_program(ROOM);
}
