// Room: /u/mei/caoyuan5.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "戈壁");
	set("long", @LONG
戈壁平坦如镜，和沙漠上的沙丘起伏全然不同，只见一片平沙，凝眸远眺，
只觉天地相接，万籁无声，身当此境，不禁也生栗栗之感，顿觉大千无限，一己
渺小异常。
LONG
	);
	set("no_new_clean_up", 0);
	set("outdoors", "caoyuan5");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"caoyuan4",
        "south" : "/d/mingjiao/shanjiao",
]));

	setup();
	replace_program(ROOM);
}
