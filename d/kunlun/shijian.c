//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","试剑厅");
	set("long", @LONG
这里是昆仑派弟子练习剑法武功的所在，而所谓的厅，其实就是一个露天
的场地，只不过有青砖铺地而已。这不，从这里还能看到东面的白牛山。从这
里往西面是一个更低的坳地，昆仑派中弟子大都住在那边。北面是一个独门小
院，进去是掌门人的铁琴居。
LONG );
	set("exits", ([
		"south"  : __DIR__"sanshengju",
		"north"  : __DIR__"tieqin",
		"east"  : __DIR__"bingqiku",
		"westdown" :  __DIR__"qipan",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 5,
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

