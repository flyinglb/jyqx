// Room: /d/songshan/songyueta.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����ԭ�Ǳ�κ�빬��Т������Ϊ��Ժ�����巽�н�������Χ��
��ɮ�����ơ�Ժ�ڷ綯����ҡ���ң�����һ���徲��
LONG );
	set("exits", ([
		"southdown" : __DIR__"shandao3",
		"northwest" : __DIR__"shandao4",
		"west"      : __DIR__"songyueta",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

