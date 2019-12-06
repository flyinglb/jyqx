#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short","护法宫");
    set("long",@LONG
这里是七星楼护法的房间。
LONG
    );
    set("sleep_room","1");
    set("exits", ([ /* sizeof() == 2 */
        "north" : __DIR__"dating2",
            "south"    : __DIR__"liangong12",
    ]));
    set("no_fight",1);
    set("no_sleep_room",1);
    set("no_steal",1);
    set("no_beg",1);
    setup();
}
