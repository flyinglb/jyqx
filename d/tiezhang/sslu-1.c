// Room: /u/zqb/tiezhang/sslu-1.c

inherit ROOM;

void create()
{
	set("short", "碎石路");
	set("long", @LONG
    你走在一条用碎石铺成的小路上。两旁山势低缓，长满了翠绿的
毛竹，阵阵微风吹过，耳旁便响起一片沙沙声。
LONG	);
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"sslu-2.c",
  "westdown" : __DIR__"pingtai",
]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	setup();
	replace_program(ROOM);
}

