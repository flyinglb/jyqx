#include <room.h>
inherit ROOM;

void create()
{
    set("short","大厅");
    set("long",@LONG
这里七星楼总堂的三楼,东，西，北，三面各有一个长廊，不知道通向那里
还是别乱走了，迷路就遭了。
LONG
    );
    set("sleep_room","1");
    set("exits",([
        "west" : __DIR__"chang",
        "east" : __DIR__"chang2",
        "north" : __DIR__"chang3",
        "down"  : __DIR__"dating2",
    ]));
    set("no_kill",1);
    set("no_fight",1);
    set("no_hit",1);
    set("steal",1);
    setup();
}
