// liangong2.c

inherit ROOM;

void create()
{
	set("short", "小鸟居");
	set("long", @LONG
  走进这里，首先映入眼帘的是一副朱耸的“荷花水鸟图”，这是一间并不太大房间，
显得很精巧别致。窗外不时有阵阵花香飘进来，靠窗有张小床，可供人休憩。
LONG
	);
        set("exits", ([ 
		"north" : __DIR__"huayuan1", 		
]));
        set("no_fight",0);
        set("no_steal",0);
        set("sleep_room",1);
	setup();
	replace_program(ROOM);
}
