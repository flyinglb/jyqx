//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","南大院");
	set("long", @LONG
这是南庄武家的前院，院墙边靠着一些刀剑，显然主人家是习武的。院里
种了两棵茶树，虽然长的不很茂盛，但也很让人吃惊的了，因为在这西北高寒
的地方应该根本不会生长这种植物的。院里几个仆役正在搬运木材。
LONG );
	set("exits", ([
		"east"  : __DIR__"xiangfang",
		"north" : __DIR__"zhuwu",
		"south" : __DIR__"qianting",
	]));
	set("objects", ([
		__DIR__"npc/jiading" : 2,
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

