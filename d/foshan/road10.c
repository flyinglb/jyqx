//Room: /d/foshan/road9.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","林间道");
	set("long",@LONG
这里是一条林间小道，在树丛中蜿蜒。这里山林茂密，多产毒
虫，各位行路要十分小心。
LONG);
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
            "north" : __DIR__"road8",
            "south" : "/d/players/honglianjiao",
	]));
	setup();
	replace_program(ROOM);
}

