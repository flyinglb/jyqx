// Room: /d/songshan/shandao4.c
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
		"northup"   : __DIR__"fawangsi",
		"southeast" : __DIR__"songyuesi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "songshan");
	setup();
	replace_program(ROOM);
}

