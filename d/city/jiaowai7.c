// Room: /d/city/jiaowai7.c
// Jan. 8.1998 by Venus
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "草地");
    set("long", @LONG
这是扬州郊外的一片芳草地，落英缤纷，蜂歌蝶舞，朝露
夕光，沁人心脾。真是踏青远足好时光。
LONG );
    set("exits", ([
        "east" : __DIR__"jiaowai6",
        "west" : __DIR__"nanmen",
        "north": __DIR__"hnme",
    ]));
    set("no_clean_up", 0);
    set("outdoors", "yangzhou");
    setup();
    create_door("north", "雕花小门", "south", DOOR_CLOSED);
}
int valid_leave(object me, string dir)
{
    me = this_player();
    if (((me->query("id")!="hnme") && (me->query("id")!="jan")) && dir == "north")
    {
       return notify_fail(RED"那是人家的私宅，别去讨嫌了！\n"NOR);
    }
    return ::valid_leave(me, dir);
}

