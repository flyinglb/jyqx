// Room: /d/songshan/shandao5.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
��������ɽɽ�������ɴ�أ�ɽ�����ʱ��Ʈ����Զ��ɽ��
Ȯ�ͼ��䣬�����ɷ�֮�С�
LONG );
	set("exits", ([
		"northup"   : __DIR__"chaotian",
		"southwest" : __DIR__"fawangsi",
		"southdown" : __DIR__"tieliang",
	]));
	set("outdoors", "songshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

