//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","三圣居");
	set("long", @LONG
当年“昆仑三圣”何足道在此群山围绕的山坳里创下昆仑一派，其后起门
人弟子逐渐建立起颇具规模的厅堂院落，这座正中的大堂为纪念其开门祖师而
命名为“三圣居”。从这厅堂向后面就是昆仑派的试剑厅，东西两面分别是弈
道厅和琴羽厅。
LONG );
	set("exits", ([
		"south"  : __DIR__"sansheng",
		"north"  : __DIR__"shijian",
		"west"  : __DIR__"yidao",
		"east" :  __DIR__"qinyu",
	]));
        set("valid_startroom", 1);
	set("objects", ([
		__DIR__"npc/weisiniang" : 1,
	]));
	set("no_clean_up", 0);
	setup();
        "/clone/board/kunlun_b"->foo();
	replace_program(ROOM);
}

