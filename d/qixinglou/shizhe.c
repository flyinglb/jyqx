#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short","风云阁");
    set("long",@LONG
这里是跋寒锋的房间,只见墙上挂着他的利器:意难平,好像有什么不平事一样
还有另一边有一幅画，画中少女，听说是他的初恋情人!

LONG
    );
    set("sleep_room","1");
    set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"liangong7",
        "southeast" : __DIR__"chang4",
    ]));
    set("no_fight",1);
    set("no_sleep_room",1);
    set("no_steal",1);
    set("no_beg",1);
    setup();
}
