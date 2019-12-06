inherit ROOM;
void create()
{
        set("short", "执法堂");
        set("long", @LONG
这是飘雪山庄的执法堂，是专门用来对那些犯了庄规的
弟子进行惩罚的地方。
LONG );
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
        set("exits", ([
                "south"  : __DIR__"piaoxue2",
        ]));
        setup();
}
