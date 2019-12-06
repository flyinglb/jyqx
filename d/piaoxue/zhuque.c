inherit ROOM;
void create()
{
        set("short", "长廊");
        set("long", @LONG
这是一条通往朱雀堂的长廊，你只见雕梁画栋，
精美绝伦，使你舍不得离开。
LONG );
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
        set("exits", ([
                "south"  : __DIR__"dayuan3",
                "north"  : __DIR__"piaoxue",
        ]));
        setup();
}