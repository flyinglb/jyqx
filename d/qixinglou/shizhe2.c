#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short","�����");
    set("long",@LONG
��������¥ʹ�߳��Ļ���ң�.

LONG
    );
    set("sleep_room","1");
    set("exits", ([ /* sizeof() == 2 */
        "southwest" : __DIR__"chang4",
        "east" : __DIR__"liangong8",
    ]));
    set("no_fight",1);
    set("no_sleep_room",1);
    set("no_steal",1);
    set("no_beg",1);
    setup();
}
