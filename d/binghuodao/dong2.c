// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "�Զ�");
	set("long", @LONG
��ʪ�ֳ���һ��ʯ��,��ɢ����Ұ�޵��ȳ�.
LONG );
set("exits", ([
		"north" : __DIR__"dong1",
	         "east" : __DIR__"dong2",
	        "south" : __DIR__"dong2",
	        "west"  : __DIR__"dong3",
	]));

        set("outdoors", "binghuodao");
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

