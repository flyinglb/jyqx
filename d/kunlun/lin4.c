//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","林间小径");
	set("long", @LONG
这是一条庄子后面密林中的一条小路，小路崎岖不平，两旁是很多不甚高
大的树，有一些已经被砍伐，只剩下树桩了。
LONG );
	set("exits", ([
		"east" : __DIR__"lin3",
		"north" : __DIR__"mudi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

