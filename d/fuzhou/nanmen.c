// Room: /d/fuzhou/nanmen.c
// Date: May 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����Ǹ������š�
LONG );
	set("exits", ([
		"south" : __DIR__"zhongzhou",
                "north" : __DIR__"nanmendou",
	]));
	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

