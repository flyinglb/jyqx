// liangong5.c

inherit ROOM;

void create()
{
	set("short", "玄武堂");
	set("long", @LONG
走进堂内，只见这里没什么摆设，几乎空空落落，但有几个剑庐中人。有的在
修炼内力，有的在练习拳脚。为了方便大家修炼，庄主专门为大家布置了几张床
在旁边，好在这里很大，也不碍着什么。你可以开始修炼了。
LONG
	);
        set("exits", ([ 
		"east" : __DIR__"huayuan2",
		
]));
        set("no_fight",0);
        set("no_steal",0);
        set("sleep_room",1);
	setup();
	replace_program(ROOM);
}
