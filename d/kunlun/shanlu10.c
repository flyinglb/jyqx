//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","昆仑山路");
	set("long", @LONG
盘绕在山间的路越来越高，走到后来几乎是在山梁上了。远远望去，无尽
的云海踩在脚下，而高处更有层层的云，天和地的尽头全然融合在了一起，天
好象也低了。在脚下云海的空隙间看西边，西南是无数有如刀削般的高山，西
北的路是渐低的，远处可以看到山与山之间流沙的戈壁。
LONG );
	set("exits", ([
//		"northwest"  : "/map/mingjiao/gebi1",
		"southwest"  : __DIR__"songlin1",
		"southeast"  : __DIR__"shanlu9",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

