#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short","大厅");
    set("long",@LONG
这里七星楼总堂的二楼,向北是七星楼新月堂堂主水柔晶房间，
东，西，是两条长廊，不知道是去哪里，还是别乱走了，迷路就遭了。

LONG
    );
    set("sleep_room","1");
    set("exits",([
        "up"        : __DIR__"dating3",
        "down"      : __DIR__"dating1",
        "south"     : __DIR__"hufa",
        "east"      : __DIR__"chang4",
        "west"      : __DIR__"chang5",
        "north"     : __DIR__"tangzhu"
    ]));
    set("no_kill",1);
    set("no_fight",1);
    set("no_hit",1);
    set("steal",1);
    setup();
}
