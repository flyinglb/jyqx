//fende.c

inherit ROOM;

void create()
{
	set("short", "�ص�");
	set("long",
	     "�����ǻ�����ɭ�Ļķصء�\n"
	);
	set("outdoors", "baituo");
//        set("no_clean_up", 0);
	set("exits", ([
		"southwest" : __DIR__"xiaolu1",
	]));
	set("objects" , ([
	     __DIR__"npc/guafu" : 1,
	     ]) );
	setup();
	replace_program(ROOM);
}
