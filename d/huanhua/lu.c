// lu.c

inherit ROOM;

void create()
{
	set("short", "青石路");
	set("long", @LONG
这是一条长长的青石路，从东边一直通到西边，一眼望去，路
的尽头座落着一座大宅。两旁百花争艳。令人留连忘返。
LONG
	);
	set("exits", ([
		"west" : __DIR__"damen",
		"east" : "/d/npc/m_weapon/m_room1",
]));
 	set("no_clean_up", 0);
	setup();
}
