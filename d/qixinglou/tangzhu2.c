#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short","会客室");
    set("long",@LONG
这是七星楼天煞堂堂主风沙的会客室。

LONG
    );
    set("sleep_room","1");
    set("exits", ([ /* sizeof() == 2 */
	"south" : __DIR__"liangong10",
        "northwest" : __DIR__"chang5",
    ]));
    set("no_fight",1);
    set("no_sleep_room",1);
    set("no_steal",1);
    set("no_beg",1);
    setup();
}
