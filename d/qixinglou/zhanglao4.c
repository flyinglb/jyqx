#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short","会客室");
    set("long",@LONG
这是四大长老之一天下无双的会客室，室内种着遍地兰花，这是为什么呢？大概只有无双长老才知道吧！

LONG
    );
    set("sleep_room","1");
    set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"liangong6",
        "east" : __DIR__"chang3",
    ]));
    set("no_fight",1);
    set("no_sleep_room",1);
    set("no_steal",1);
    set("no_beg",1);
    setup();
}
