#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short","新月宫");
    set("long",@LONG
这是七星楼新月堂堂主新月格格水柔晶的寝宫，北面是新月格格没事做练功用
的练功房，南面是去七星楼其他人的小路。

LONG
    );
    set("sleep_room","1");
    set("exits", ([ /* sizeof() == 2 */
	"south" : __DIR__"dating2",
        "north" : __DIR__"liangong9",
    ]));
    set("no_fight",1);
    set("no_sleep_room",1);
    set("no_steal",1);
    set("no_beg",1);
    setup();
}
