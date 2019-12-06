// liangong.c

inherit ROOM;

void create()
{
	set("short", "飞龙阁");
	set("long", @LONG
这里是一间很大的房屋，正面的墙上刻着一条飞龙，龙腾飞跃，极有气势。两旁
站几个大汉，手中抱着九环大刀。屏风的后面就是主人的休息之所了。
LONG
	);
        set("exits", ([ 
		"west" : __DIR__"huayuan1", 		
]));
        set("no_fight",0);
        set("no_steal",0);
        set("sleep_room",1);
	setup();
	replace_program(ROOM);
}
