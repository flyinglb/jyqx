//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","正房");
	set("long", @LONG
似乎世上所有大宅院的正房都是这样摆设的：一张巨大的八仙桌和两排高
背椅。在房间的正面墙壁上悬挂着一幅青山碧水图，八仙桌上放了文房四宝，
包括一只硕大的笔。房间北面有门通向后宅，侧面还有一个小门，平时都是关
着的。
LONG );
	set("exits", ([
		"west"  : __DIR__"huilang",
		"north" : __DIR__"neiyuan1",
		"south" : __DIR__"beiyuan",
	]));
	set("objects", ([
		__DIR__"npc/zhuchangling" : 1,
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

