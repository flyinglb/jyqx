inherit ROOM;
void create()
{
        set("short", "会议厅");
        set("long", @LONG
这是黑手成员平时开会的地方，江湖中有很多举足轻重的大事
就是在这里决定的。屋子中间放着一张木桌，周围是五把椅子。桌
子上放着一套茶具，五个茶杯，以备开会时品茶之用。
LONG );
        set("no_sleep_room", "1");
        set("no_fight","1");
        set("no_steal", "1");
        set("no_clean_up", 0);
        set("exits", ([
                "north"  : __DIR__"yegong",
                "west"  : __DIR__"yegong2",
                "east"  : __DIR__"xiaogong",
                "south"  : __DIR__"dating1",
        ]));
        setup();
        "/u/xyc/heishou_b.c"->foo();
}
