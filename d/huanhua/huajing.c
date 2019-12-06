// huajing.c

inherit ROOM;

void create()
{
	set("short", "花径");
	set("long", @LONG
一条花丛中的小径，红花绿柳，蜂蝶飞舞，你握剑的手也不由松弛下来。南面的
小山上有座精致的小楼。
LONG
	);
        set("exits", ([ 
		"north" : __DIR__"liangong4",
		"south" : __DIR__"yaoyue", 		
]));
        set("no_fight",0);
        set("no_steal",0);
        set("sleep_room",0);
	setup();
	replace_program(ROOM);
}
