// Room: /city/duchang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�ĳ�");
	set("long", @LONG
��������������ͨ��ͬ�ķ��䡣�����ǹ���С�ݡ�
LONG );
	set("exits", ([
		"east"  : "/inherit/room/eproom",
		"west"  : "/inherit/room/wproom",
		"south" : "/inherit/room/sproom",
		"north" : "/inherit/room/nproom",
		"down"  : __DIR__"duchang",
		"up"    : __DIR__"qiyuan",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

