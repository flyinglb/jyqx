// Room: /d/city/qiyuan.c

inherit ROOM;

void create()
{
	set("short", "棋牌室");
	set("long", @LONG
这是一间专门为棋迷们特别设计的棋牌室。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"duchang2",
]));
	set("objects", ([
		__DIR__"obj/cch" : 1,
	]));

	setup();
	replace_program(ROOM);
}
