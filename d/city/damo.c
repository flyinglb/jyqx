// Room: /city/damo.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "��Į");
	set("long", @LONG
da mo 
��Ҫ�����˵������
LONG
	);

	set("exits", ([
		"east" : __DIR__"road1",
	]));

	setup();
	replace_program(ROOM);
}

