// liangong3.c

inherit ROOM;

void create()
{
	set("short", "风雨楼");
	set("long", @LONG
走进这里你顿时感到浑身一轻，如沐春风，对面的墙上挂着一幅沈周的“落花
诗意图”，清新淡雅，意境悠远。靠窗有一张床，很是整洁。
LONG
	);
        set("exits", ([ 
		"south" : __DIR__"huayuan1", 		
]));
        set("no_fight",0);
        set("no_steal",0);
        set("sleep_room",1);
	setup();
	replace_program(ROOM);
}
