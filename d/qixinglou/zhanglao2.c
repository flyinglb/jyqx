#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short","会客室");
    set("long",@LONG
这是长老净呵的居室。

LONG
    );
    set("sleep_room","1");
    set("exits", ([ /* sizeof() == 2 */
        "south" : __DIR__"liangong4",
        "southeast" : __DIR__"chang2",
    ]));
    set("no_fight",1);
    set("no_sleep_room",1);
    set("no_steal",1);
    set("no_beg",1);
    setup();
}
