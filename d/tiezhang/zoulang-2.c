// Room: /u/zqb/tiezhang/zoulang-2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ�������ϣ������ƺ��з���Ļ�������
LONG	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zoulang-3",
  "east" : __DIR__"wztang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

