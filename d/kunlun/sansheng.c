//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","三圣坳");
	set("long", @LONG
这里遍地绿草如茵，到处果树香花，叫人想不到在这荒寒之处竟然有这般
好地方。原来这里四处都是插天高山，挡住了寒气，又有昆仑弟子东至江南西
至天竺各处移来的许多奇花异树，才装点出这地处西北荒山上的一个武林胜地。
LONG );
	set("exits", ([
		"north"  : __DIR__"sanshengju",
		"southup"  : __DIR__"shanlu7",
	]));
	set("objects", ([
		__DIR__"npc/xihuazi" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

