// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
��������޼�һ��ס��ɽ��,�Ա�ס��лѷ.
�Ŵ�ɽ�򸾵�����,��Щ�򵥵�����.
LONG );
set("exits", ([
//                "north" : __DIR__"whome",
 //                "east" : __DIR__"road5",
              "south" : __DIR__"home",
  //             "west"  : __DIR__"zhome",
        ]));

        set("objects", ([
                __DIR__"npc/obj/chaidao" : 1,
                        ]));
        set("outdoors", "binghuodao");
//      set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

