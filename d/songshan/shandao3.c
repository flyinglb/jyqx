// Room: /d/songshan/shandao3.c
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
		"northup"   : __DIR__"songyuesi",
		"southeast" : __DIR__"shuyuan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "songshan");
	setup();
	replace_program(ROOM);
}

