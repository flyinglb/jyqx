// Room: /d/gaochang/room60.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "昆仑山");
	set("long", @LONG
山上积雪更厚，道路崎岖，行走自是费力。转过两个山坡，进了一座大松林。
林中松树都是数百年的老树，枝柯交横，树顶上压了数尺厚的白雪，是以林中雪
少，反而好走。
LONG
);
	set("no_new_clean_up", 0);
	set("outdoors", "room60");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhang" : 3,
]));
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"room59",
  "west" : __DIR__"room61",
]));

	setup();
	replace_program(ROOM);
}
