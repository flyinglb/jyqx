// Room: /u/zqb/tiezhang/shanlu-2.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
    ������һ����᫵�ɽ·�ϣ�����ɽ����������ݹ������м�һ��
��С·������һ����ǿ��ȥ��
LONG	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"guangchang.c",
  "south" : __DIR__"shanlu-1.c",
]));
	set("no_clean_up", 0);
   set("objects", ([ /* sizeof() == 3 */
      __DIR__"npc/huiyi" : 2, ]));
	set("outdoors", "tiezhang");

	setup();
	replace_program(ROOM);
}

