// Room: /u/zqb/tiezhang/zoulang-1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ�������ϡ���������ڴ������������������
LONG	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"bqshi",
  "west" : __DIR__"wztang",
  "east" : __DIR__"zoulang-4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

