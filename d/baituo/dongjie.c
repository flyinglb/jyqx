//dongjie

inherit ROOM;

void create()
{
	set("short", "����");
	set("long",
	     "������С��Ķ��֡��ϱ��и������̣����洫����������\n"
	 "�����������Ϸ��ǻ����ĸ�ڣ�����������С·����ɽ��\n"
	);
	set("outdoors", "baituo");
	set("exits", ([
		"west" : __DIR__"xijie",
		"south" : __DIR__"datiepu",
		"southeast" : __DIR__"gebi",
		"northeast" : __DIR__"xiaolu1",
	]));
//        set("no_clean_up", 0);
	set("objects",([
		__DIR__"npc/playboy" : 1,
	]));
	setup();
	replace_program(ROOM);
}
