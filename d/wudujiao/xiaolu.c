// by mayue

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
һ��С·�������죬���ܾ��ǻ������������ʱ��������
�ࡣǰ����һ��СС��ɽ�ԡ�
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
		"northwest" : __DIR__"road3",
		"southup" : __DIR__"shanlu2",
//		"west" : __DIR__"wumiao",
//		"north" : __DIR__"road3",
	]));
        set("objects", ([
                "/d/wudang/npc/yetu": 3,
	]));

	setup();
	replace_program(ROOM);
}

