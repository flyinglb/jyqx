// Room: /u/zqb/tiezhang/road-2.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
    ������һ����������Ļ���·�ϣ���������ɭɭ�����֡������Ǵ��潻�磬
��˵���������˳�û�����ɾ�����
LONG	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road-3",
  "northeast" : __DIR__"road-1",
]));
	set("no_clean_up", 0);
	set("outdoors", "wudang");

	setup();
	replace_program(ROOM);
}

