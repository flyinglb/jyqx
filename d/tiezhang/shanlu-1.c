// Room: /u/zqb/tiezhang/shanlu-1.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
    你走在一条崎岖的山路上，道旁山峰壁立，长草过腰，中间一条
羊肠小路，仅容一人勉强过去。
LONG	);
    set("outdoors", "tiezhang");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shanlu-2",
  "southdown" : __DIR__"shanmen.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

