// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
������һƬ��ݵ�,��ֻ�ɰ���С����,�ڳԲ�.
LONG );
set("exits", ([
	         "north" : __DIR__"road10",	
          	//  "east" : __DIR__"road8",
	        // "south"  : __DIR__"road12",
	]));
    set("objects", ([
		__DIR__"npc/baitu" : 3,
			]));
        set("outdoors", "binghuodao");
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

