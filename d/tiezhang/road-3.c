// Room: /u/zqb/tiezhang/road-3.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
    ������һ����������Ļ���·�ϣ���������ɭɭ�����֡������Ǵ��潻�磬
��˵���������˳�û�����ɾ�����
LONG	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"shanjiao",
  "east" : __DIR__"road-2",
]));
	set("no_clean_up", 0);
	set("outdoors", "wudang");

	setup();
	replace_program(ROOM);
}

