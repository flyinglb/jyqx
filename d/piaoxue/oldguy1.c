inherit ROOM;
void create()
{
        set("short", "长老院");
        set("long", @LONG
这是飘雪山庄的长老院，是各大长老护法们聚集议事的地方。
LONG );
	set("no_steal", "1");
	set("no_sleep_room", "1");
        set("no_fight","1"); 
	set("no_clean_up", 0);
        set("exits", ([
                "west"  : __DIR__"piaoxue2",
        ]));
        setup();
}
