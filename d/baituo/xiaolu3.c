//xiaolu3

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long",
	     "������һ����ɽ��С·����������ɽ����û��Ҫ����С�ġ�\n"
	);
	set("outdoors", "baituo");
	set("exits", ([
		"northeast" : __DIR__"xiaolu4",
//		 "northwest" : __DIR__"maozhu ",
		"southdown" : __DIR__"xiaolu2",
	]));
	set("objects",([
		__DIR__"npc/shanzei1" : 1,
	]));
//        set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
