// Room: /u/mei/room59.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "昆仑山");
	set("long", @LONG
这茫茫山坡上一片白雪，四下并无行人，山势渐陡，雪积得厚厚的，转过两
个山坳，山道更是险峻。树木丛生，山石嶙峋，行走甚是不便。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"room60",
  "eastdown" : __DIR__"room58",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room59");

	setup();
	replace_program(ROOM);
}
