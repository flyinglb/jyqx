// Room: /u/zqb/tiezhang/shangu-2.c

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
    ������һ����խ��ɽ��֮�У�����ɽ�������ֱ������������Գ 
��֮�����ص��ڼž��Ŀչ�֮�С�
LONG	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"juebi-1",
  "southwest" : __DIR__"shangu-1",
]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	setup();
	replace_program(ROOM);
}

