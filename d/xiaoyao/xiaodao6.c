// Room: /d/xiaoyao/xiaodao6.c

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
这里就是逍遥派弟子练功的地方，几个练功用木人放在地上。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  "/d/shaolin/npc/mu-ren" : 5,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"xiaodao2",
]));

	setup();
	replace_program(ROOM);
}
