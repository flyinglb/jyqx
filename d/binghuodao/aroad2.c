// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "С·");
	set("long", @LONG
һ���ݴ���,̤����С·.����·��,���ƽ���.
����Ҳ������������.
LONG );
set("exits", ([
	          "southeast" : __DIR__"road10",
	          "northwest" : __DIR__"aroad3",	
          	 // "east" : __DIR__"road4",
	        // "west"  : __DIR__"road8",
	]));

        set("outdoors", "binghuodao");
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

