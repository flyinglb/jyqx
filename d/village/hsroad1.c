// hsroad1.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С��ϱ�ͨ�����ݳǡ�
LONG );
        set("outdoors", "wudang");

	set("exits", ([
		"north" : __DIR__"hsroad2",
		"south" : "/d/city4/road2",
	]));
	set("objects", ([
		__DIR__"npc/girl" : 4,
	]));

//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

