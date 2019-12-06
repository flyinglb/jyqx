#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short","魔龙殿");
    set("long",@LONG
这是七星楼楼主龙剑的会客室，墙上挂着一口千年玄铁打造的宝剑，剑未出鞘，已经杀气逼人。

LONG
    );
    set("sleep_room","1");
    set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"liangong",
        "south" : __DIR__"chang",
    ]));
    set("no_fight",1);
    set("no_sleep_room",1);
    set("no_steal",1);
    set("no_beg",1);
    setup();
}
