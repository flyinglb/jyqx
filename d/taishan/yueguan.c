// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "�¹۷�");
	set("long", @LONG
������λ�������������ɽ�룬��ʯ�ܴأ���ߵĵط�һʯ׿����
��Ϊ���ӷ塣�����߱���̩ɽ�������š�
LONG );
	set("exits", ([
		"east" : __DIR__"nantian",
		"northup" : __DIR__"xitian",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}

