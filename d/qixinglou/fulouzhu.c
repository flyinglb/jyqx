#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short","孤星堂");
    set("long",@LONG
这是七星楼副楼主萧白的居室,旁边有一个大书架,书架
里放着萧白多年以来收集的武功秘籍。旁边还有一张萧白最
近才照的相片,旁边还有一台崭新的VCD，肯定是萧白休闲所
用的。
LONG
    );
    set("sleep_room","1");
    set("exits", ([ /* sizeof() == 2 */
        "east" : __DIR__"liangong2",
        "north" : __DIR__"chang",
    ]));
    set("no_fight",1);
    set("no_sleep_room",1);
    set("no_steal",1);
    set("no_beg",1);
    setup();
}
