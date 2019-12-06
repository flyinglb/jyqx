#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short","会客室");
    set("long",@LONG
这是四大长老之一长老傅采林的居室。

LONG
    );
    set("sleep_room","1");
    set("exits", ([ /* sizeof() == 2 */
        "east" : __DIR__"liangong5",
        "west" : __DIR__"chang3",
    ]));
    set("no_fight",1);
    set("no_sleep_room",1);
    set("no_steal",1);
    set("no_beg",1);
    setup();
}
