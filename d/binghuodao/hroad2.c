// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "小路");
        set("long", @LONG
一条草丛中,踏出的小路.
LONG );
set("exits", ([
                 "north" : __DIR__"hroad3",        
          //        "east" [D: __DIR__"road8",
                 "southeast"  : __DIR__"hroad1",
        ]));

        set("outdoors", "binghuodao");
//      set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

