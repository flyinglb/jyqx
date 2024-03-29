// Room: /u/zqb/tiezhang/sslin-3.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "松树林");
	set("long", @LONG
    你走进一片黑压压的松树林，这里的松树枝繁叶茂，树冠相叠，
遮天蔽日。几素阳光从树梢间照射下来，在淡淡的雾气中，形成条条白色
的光柱，煞是好看。你走着走着，忽然发现自己已迷失在这片松林中，找
不到出去的路了。
LONG	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"sslin-4",
  "east" : __FILE__,
  "south" : __DIR__ "sslin-2",
  "north" : __FILE__,
]));
    set("objects",([
            __DIR__"npc/laohu"  :        1,
    ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

