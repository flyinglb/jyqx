// Room: /u/zqb/tiezhang/shanlu-8.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
    ������һ����᫵�ɽ·�ϣ�����ɽ����������ݹ������м�һ��
��С·������һ����ǿ��ȥ��
LONG	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"dezj",
  "northup" : __DIR__"shanlu-9",
]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	setup();
	replace_program(ROOM);
}

