inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ����������Ĵ���������������У�ʮ�����֡����߾��ǳ����š�
LONG );
        set("outdoors", "city2");
	set("exits", ([
		"west" : __DIR__"wangfu2",
		"east" : __DIR__"chaoyang",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}


