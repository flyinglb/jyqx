// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "�յ�");
        set("long", @LONG
һ�鿪�ٳ��Ŀյ�,�������˹���.
LONG );
set("exits", ([
"south" : __DIR__"mroad1",                
"north"  : __DIR__"home",
"northeast"  : __DIR__"xhome",
        ]));

        set("outdoors", "binghuodao");
//      set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

