// Room: /d/gaochang/room1.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这里的地上是一种黄褐色，红褐色的石砾镶嵌在细细的黄沙之中，
给人以极其怪异的感觉。这里就是西域与中原的中间地带，再往西就是
边塞。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room2",
  "east" : "/d/heimuya/road2",
]));
	set("outdoors", "room1");
	set("no_new_clean_up", 0);

	setup();
	replace_program(ROOM);
}
