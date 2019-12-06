#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short","会客室");
    set("long",@LONG
这是四大长老之一长老水中月的居室，什么都没有，大概是年龄太大，糊涂了吧？

LONG
    );
    set("sleep_room","1");
    set("exits", ([ /* sizeof() == 2 */
        "south" : __DIR__"liangong3",
        "northwest" : __DIR__"chang2",
    ]));
    set("no_fight",1);
    set("no_sleep_room",1);
    set("no_steal",1);
    set("no_beg",1);
    setup();
}
