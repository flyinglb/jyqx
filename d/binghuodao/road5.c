// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "С·");
        set("long", @LONG
һ���ݴ���,̤����С·.
LONG );
set("exits", ([
         //       "north" : __DIR__"mroad1",
                 "east" : __DIR__"road7",
           //     "south" : __DIR__"anbian",
                "west"  : __DIR__"road3",
        ]));

        set("outdoors", "binghuodao");
//      set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

