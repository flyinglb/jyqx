// Room: /city2/duchang2.c

inherit ROOM;

void create()
{
	set("short", "�ĳ�");
	set("long", @LONG
��������������ͨ��ͬ�ķ��䡣
LONG );
	set("exits", ([
		"east"  : "/d/city2/eproom",
		"west"  : "/d/city2/wproom",
		"south" : "/d/city2/sproom",
		"north" : "/d/city2/nproom",
		"down"  : __DIR__"duchang",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

