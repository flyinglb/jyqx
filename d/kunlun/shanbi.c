//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","山壁");
	set("long", @LONG
一条几乎无法攀登的冰雪山路通到了这里，而再想向上走一点也几乎是
没有可能的了。很奇怪的是在这冰雪覆盖的近乎竖直的山壁上居然长了一些细
小的草本植物。你也不知道这些不知名的草里面有没有比灵芝更有价值的东西
了。
LONG );
	set("exits", ([
		"westdown" : __DIR__"baixiang",
	]));
	set("objects", ([
		__DIR__"obj/lingzhi" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}
