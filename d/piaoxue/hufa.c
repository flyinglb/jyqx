inherit ROOM;
void create()
{
        set("short", "护法堂");
        set("long", @LONG
这是飘雪山庄的护法堂，是飘雪山庄两位护法呆的地方。
LONG );
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
        set("exits", ([
                "north"  : __DIR__"piaoxue2",
        ]));
        setup();
}
