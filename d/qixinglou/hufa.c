#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short","������");
    set("long",@LONG
����������¥�����ķ��䡣
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
