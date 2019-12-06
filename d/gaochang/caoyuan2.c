// Room: /d/gaochang/caoyuan2.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "草原");
	set("long", @LONG
这是一片无边无际的草原，半人高的青草随风而动，正如江湖中的你，随著
江湖之中汹涌的波涛，四处飘摇。你想到江湖中的无奈,不禁沧然泪下。 
LONG
);
	set("no_new_clean_up", 0);
	set("outdoors", "caoyuan");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yanshu" : 2,
]));
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"caoyuan3",
  "north" : __DIR__"caoyuan1",
]));

	setup();
	replace_program(ROOM);
}
