//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","后院");
	set("long", @LONG
这里是庄子的后宅了，院里一男一女两个少年人正在院子里剑舞嬉戏。院
墙边堆积了很多木材，不知做什么用的。在院子的周边，有几座房舍。
LONG );
	set("exits", ([
		"east"  : __DIR__"guifang",
		"west"  : __DIR__"lin1",
		"north" : __DIR__"qianting",
		"south" : __DIR__"woshi",
	]));
	set("objects", ([
		__DIR__"/npc/wuqingying" : 1,
		__DIR__"/npc/weibi" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

