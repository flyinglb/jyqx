// mishi.c

inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
这里是一间空空的屋子，只有一桌，一凳，一床而已，非常简单。
LONG
	);
        set("exits", ([ 
		"south" : __DIR__"shufang", 		
]));
        set("no_fight",0);
        set("no_steal",0);
        set("sleep_room",1);
	setup();
	replace_program(ROOM);
}
