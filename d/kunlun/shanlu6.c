// By Robin 2000.3.8

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","昆仑山路");
	set("long", @LONG
越来越高的群山之间出现了一片相对低矮又稀疏的山丘，而密集如海的云
雾也稀松了许多，让人可以直望南天见到阳光。阳光下的山坡上不仅有杉林，
还有一些色彩鲜艳的花草，让人在这灰白青的天地间感觉一点异常的惊喜。看，
北面有一条小路通向一个生有浅草白花的山丘。
LONG );
	set("exits", ([
		"northup" : __DIR__"bainiu",
		"west"  : __DIR__"shanlu7",
		"eastdown"  : __DIR__"shanlu5",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

