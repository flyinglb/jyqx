// Room: /d/henshan/hsroad9.c 南岭山口
// Modified by Java on Feb.14.1998
inherit ROOM;

void create()
{
	set("short", "南岭山口");
	set("long", @LONG
这里是南岭的一个山口。南面是岭南的大镇佛山，北面是湖南的
地界。岭南广东富庶繁盛，颇有豪侠之士。
LONG );
        set("outdoors", "henshan");

	set("exits", ([
		"northdown" : __DIR__"hsroad5",
		"southdown" : "/d/foshan/nanling",
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

