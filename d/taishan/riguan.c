// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "�չ۷�");
	set("long", @LONG
������λ�������������ɽ�룬��ʯ�ܴأ���ߵĵط�һʯ
׿������Ϊ���ӷ塣�����߱���̩ɽ�������š�
LONG );
	set("exits", ([
		"westup" : __DIR__"yuhuang",
		"eastup" : __DIR__"tanhai",
	]));
	set("objects", ([
		__DIR__"npc/tianmen" : 1,
	]));
//	set("outdoors", "taishan");
	set("no_clean_up", 0);
	setup();
	"/clone/board/taishan_b"->foo();
}

