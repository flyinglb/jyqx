// Room: /d/city2/ximenwai.c

inherit ROOM;

void create()
{
        set("short", "北门外");
	set("long", @LONG
这里是北京的北城门外，城外山峦起伏，行人已经不很多了。
LONG );
	set("exits", ([ /* sizeof() == 2 */
                "south" : __DIR__"anding",
                "northwest" : "/d/menggu/road1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}
