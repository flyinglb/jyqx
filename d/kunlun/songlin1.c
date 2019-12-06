//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","雪岭云杉林");
	set("long", @LONG
步入昆仑西部的群山，可以看到的依旧是云杉为主的山林，但山的样子和
东部的山完全不同。这里的山从远处看都不是一种形态，低处的依旧是昆仑山
脉的主流，如卧龙般伏野万里，高处的山则象插在龙背上的尖刺，一根根直耸
云霄，甚至有很多山的一面就根本没有山坡而仿佛是天斧劈削出来一般平滑笔
直。
LONG );
	set("exits", ([
		"northeast"  : __DIR__"shanlu10",
		"west"  : __DIR__"songlin2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

