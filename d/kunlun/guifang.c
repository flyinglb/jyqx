//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","闺房");
	set("long", @LONG
这是庄主小姐武青婴的闺房，屋里有些凌乱，与武青婴整洁清丽的外表很
不相称。女孩子美丽的外衣一般都不少，看这屋里就知道这位小姐也一定好穿，
衣裙斗篷摆得到处都是，尤其那件黑色貂裘透露出的华丽显得尤为突出。
LONG );
	set("exits", ([
		"west"  : __DIR__"houyuan",
	]));
	set("objects", ([
		__DIR__"npc/binv" : 1,
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

