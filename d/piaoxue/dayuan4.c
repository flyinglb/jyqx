inherit ROOM;
void create()
{
        set("short", "玄武堂正院");
        set("long", @LONG
这里是玄武堂的正院，再向前就是玄武堂的议事厅，
你的左右是堂内弟子练功的地方。
LONG );
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
        set("exits", ([
                "east"  : __DIR__"liangong7",
                "west" : __DIR__"liangong8",
		"north" : __DIR__"xwdian",
		"south" : __DIR__"xuanwu",
        ]));
        setup();
}