// Room: /d/songshan/chaotian.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����˫���жϣ���Ȼ����һ���Ż�������ӶϾ�������������
������������������ǳ������ˡ�
LONG );
	set("exits", ([
		"northup"   : __DIR__"shandao6",
		"southdown" : __DIR__"shandao5",
	]));
	set("outdoors", "songshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

