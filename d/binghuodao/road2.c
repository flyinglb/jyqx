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
                 "west" : __DIR__"road4",        
             "east" : __DIR__"road1",           
 //     "south"  : __DIR__"road12",
        ]));

        set("outdoors", "binghuodao");
//      set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

