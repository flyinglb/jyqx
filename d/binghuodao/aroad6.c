// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "ɽ��");
	set("long", @LONG
Сɽ���Ϲ�ľ����,ż��С����,������ȥ.
��֪����С��,׺������.
LONG );
set("exits", ([
	        //  "south" : __DIR__"aroad3",
	         // "north" : __DIR__"aroad4",	
          	"east" : __DIR__"aroad3",
	        //"west"  : __DIR__"road3",
	]));
set("objects", ([
		__DIR__"npc/baitu" : 3,
			]));
        set("outdoors", "binghuodao");
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

