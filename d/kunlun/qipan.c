//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","棋盘坳");
	set("long", @LONG
这个山坳比三圣坳地势低了一些，移植的花草也不少，但明显档次比不上
三圣坳的，主要以常青的灌木和小草为主。这里草木以棋盘状分布，坳外道路
通往四方，所以昆仑弟子称此为棋盘坳。这里向西是一片房舍，是昆仑弟子的
居处，向东而上是三圣居的试剑厅，向南是一处山谷，其间灌木丛生，据说很
少有人去过，向北是一条上山的小路，这里可以见到山上隐约的庙宇一角。
LONG );
	set("exits", ([
		"eastup" :  __DIR__"shijian",
		"west"   :  __DIR__"xiaoyuan1",
		"north"  :  __DIR__"houshan1",
//		"southdown":__DIR__
	]));
//	set("objects", ([
//	__DIR__"npc/binv" : 2,
//	]));
	set("outdoors","kunlun");
	setup();
	replace_program(ROOM);
}

