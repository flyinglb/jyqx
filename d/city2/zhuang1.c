
inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
������һ��С·�ϡ�ǰ���·��᫣����˺��١�
LONG );
	set("exits", ([
		"southwest" : __DIR__"road1",
		"north"     : __DIR__"zhuang2",
	]));
	set("objects", ([
		"/d/taishan/npc/seng-ren" : 1,
	]));
//	set("no_clean_up", 0);
 	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}



