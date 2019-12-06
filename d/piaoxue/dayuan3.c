inherit ROOM;
void create()
{
        set("short", "朱雀堂正院");
        set("long", @LONG
这里是朱雀堂的正院，再向前就是朱雀堂的议事厅，
你的左右是堂内弟子练功的地方。
LONG );
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
        set("exits", ([
                "east"  : __DIR__"liangong5",
                "west" : __DIR__"liangong6",
		"north" : __DIR__"zhuque",
		"south" : __DIR__"zqdian",
        ]));
        setup();
}