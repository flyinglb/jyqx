// Room: /d/menggu/road.c

inherit ROOM;

void create()
{
        set("short", "山路");
	set("long", @LONG
山路似乎到了尽头，北边是一片一望无际的大草原。
LONG );
	set("exits", ([ /* sizeof() == 2 */
                "south" : __DIR__"road3",
                "north" : __DIR__"cy001",
	]));
	set("no_clean_up", 0);
	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}
