// Room: /u/zqb/tiezhang/road-1.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
    ������һ����������Ļ���·�ϣ���������ɭɭ�����֡������Ǵ��潻�磬
��˵���������˳�û�����ɾ�����
LONG	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"road-2",
  "northeast" : __DIR__"lx",
]));
	set("no_clean_up", 0);
	set("outdoors", "wudang");

	setup();
	replace_program(ROOM);
}

