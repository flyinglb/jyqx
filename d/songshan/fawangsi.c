// Room: /d/songshan/fawangsi.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����������ɽ�������£���Լ��ï�������У��˵����� "��ɽ
��һʤ��" ֮�ơ�
LONG );
	set("exits", ([
		"southdown" : __DIR__"shandao4",
		"northeast" : __DIR__"shandao5",
		"northup"   : __DIR__"tayuan",
		"west"      : __DIR__"yuetai",
	]));
	set("objects", ([
		__DIR__"npc/zhong" : 1,
		__DIR__"npc/deng" : 1,
		__DIR__"npc/gao" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

