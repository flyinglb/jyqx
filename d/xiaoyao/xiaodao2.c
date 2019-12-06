// Room: /d/xiaoyao/xiaodao2.c

inherit ROOM;

void create()
{
	set("short", "林间小道");
	set("long", @LONG
这是一条长长的林间小道，从东边一直通到西边，一眼望去，看不到路
的尽头。两旁百花争艳。令人留连忘返。南边好象有香味散发出来，北边是
个兵器房。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 5 */
  "north" : __DIR__"bingqif",
  "northwest" : __DIR__"xiaodao6",
  "west" : __DIR__"xiuxis",
  "east" : __DIR__"xiaodao1",
  "south" : __DIR__"shantang",
]));
	set("outdoors", "xiaoyao");

	setup();
	replace_program(ROOM);
}
