inherit ROOM;
void create()
{
        set("short", "白虎堂正院");
        set("long", @LONG
这里是白虎堂的正院，再向前就是白虎堂的议事厅，
你的左右是堂内弟子练功的地方。
LONG );
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
        set("exits", ([
                "east"  : __DIR__"baihu",
                "west" : __DIR__"bhdian",
		"north" : __DIR__"liangong3",
		"south" : __DIR__"liangong4",
        ]));
        setup();
}