// Room: /u/zqb/tiezhang/shanlu-3.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
    ������һ����᫵�ɽ·�ϣ�����ɽ����������ݹ������м�һ��
��С·������һ����ǿ��ȥ��
LONG	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hhyuan-1",
  "northup" : __DIR__"shanlu-4",
]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	setup();
	replace_program(ROOM);
}

