// Room: /city/tianshan.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
tian shan
��Ҫ�����˵������
LONG
	);

	set("exits", ([
		"east" : __DIR__"road2",
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

