// Room: /u/zqb/tiezhang/shanlu-1.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
    ������һ����᫵�ɽ·�ϣ�����ɽ����������ݹ������м�һ��
��С·������һ����ǿ��ȥ��
LONG	);
    set("outdoors", "tiezhang");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shanlu-2",
  "southdown" : __DIR__"shanmen.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

