//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","悬崖");
	set("long", @LONG
你气喘吁吁地攀上这座高山，你以为应该到了昆仑山的最高处了，但眺
望在这更高一层的云层里，远处还有无数的山峰，由于很远了，已经根本分
不清那些山的高度和轮廓。而脚下的山路却似乎已经到了尽头，面前是一个
望不到底的悬崖。
LONG );
	set("exits", ([
		"southdown"  : __DIR__"jilu2",
        ]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}
