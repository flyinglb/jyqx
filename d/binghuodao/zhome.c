// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
��������޼�һ��ס��ɽ��,�Ա�ס��лѷ.
�޼�ס����.�������Ųݵ�,�ݵ�������Ƥ.
LONG );
set("exits", ([
          //      "north" : __DIR__"whome",
                 "east" : __DIR__"home",
 //             "south" : __DIR__"mroad3",
//               "west"  : __DIR__"zhome",
        ]));

        set("outdoors", "binghuodao");
//      set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

