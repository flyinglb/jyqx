// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
��������޼�һ��ס��ɽ��,�Ա�ס��лѷ.

LONG );
set("exits", ([
                "north" : __DIR__"whome",
 //                "east" : __DIR__"road5",
              "south" : __DIR__"mroad3",
               "west"  : __DIR__"zhome",
        ]));
set("objects", ([
                __DIR__"npc/zhangcui" : 1,
             __DIR__"npc/susu" : 1, 
             //  __DIR__"obj/" : 1,
        ]));

//        set("outdoors", "binghuodao");
//      set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

