//gebi

inherit ROOM;

void create()
{
	set("short", "���");
	set("long",
	     "�������ٽ�ɳĮ�ĸ��̲���������̡�������һ���޼ʵĴ�ɳĮ��\n"
	 "���������Կ���һ��С��\n"
	);
	set("outdoors", "baituo");
        set("no_clean_up", 0);
	set("exits", ([
		"east" : "/d/xingxiu/shamo4",
		"northwest" : __DIR__"dongjie",
	]));
	setup();
	replace_program(ROOM);
}
