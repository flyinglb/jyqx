// Room: /d/songshan/tianzhongge.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "���и�");
	set("long", @LONG
���и���������Ĵ��ţ�ԭ�ƻ��и������йŰ��������꣬��
ʯ���ٰ���������ǰʯ���٣����ƹ��ӡ���������ɽ�ĳ���̫���ڡ�
LONG );
	set("outdoors","songshan");
	set("exits", ([
		"north" : __DIR__"chongsheng",
		"south" : __DIR__"taishique",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

