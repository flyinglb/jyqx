// Room: /d/menggu/road.c

inherit ROOM;

void create()
{
        set("short", "山路");
	set("long", @LONG
这是一条盘桓在山里的路，到处都是山，看不到尽头。
LONG );
	set("exits", ([ /* sizeof() == 2 */
                "southeast" : __DIR__"road2",
                "north" : __DIR__"road4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}
