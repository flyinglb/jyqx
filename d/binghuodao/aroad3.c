// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "С·");
	set("long", @LONG
һ���ݴ���,̤����С·.����·��,���ƽ���.
�𽥵���Сɽ��.���Ϲ�ľ����,ż��С����,������ȥ.
LONG );
set("exits", ([
	          "south" : __DIR__"aroad2",
	          "north" : __DIR__"aroad4",	
          	 "east" : __DIR__"aroad5",
"west"  : __DIR__"aroad6",
	]));

        set("outdoors", "binghuodao");
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

