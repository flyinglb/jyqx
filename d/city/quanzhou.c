// Room: /city/quanzhou.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "Ȫ�ݸۿ�");
	set("long", @LONG
quanzhou
��Ҫ�����˵������
LONG );
	set("exits", ([
		"west" : __DIR__"road10",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

