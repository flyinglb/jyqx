inherit ROOM;
void create()
{
        set("short", "青龙堂正院");
        set("long", @LONG
这里是青龙堂的正院，再向前就是青龙堂的议事厅，
你的左右是堂内弟子练功的地方。
LONG );
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
        set("exits", ([
                "east"  : __DIR__"qldian",
                "west" : __DIR__"qinglong",
		"north" : __DIR__"liangong1",
		"south" : __DIR__"liangong2",
        ]));
        setup();
}