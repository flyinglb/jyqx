// Room: /u/zqb/tiezhang/zoulang-3.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ�������ϡ����洫�����󷹲˵���ζ��
LONG	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"chufang",
  "east" : __DIR__"zoulang-2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

