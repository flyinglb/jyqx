// by mayue

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
����һ�����ϵĻ��������������һƬƬ�����͵�ˮ��
�����е���ͯ������������������������������˶���������
����ͷ�󺹵ĴҴҸ�·���ƺ���������������������԰��⡣
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
//		"east" : __DIR__"zuixianlou",
		"south" : __DIR__"road3",
//		"west" : __DIR__"wumiao",
		"north" : __DIR__"road1",
	]));
        set("objects", ([
                "/d/taishan/npc/tiao-fu": 2,
	]));

	setup();
	replace_program(ROOM);
}

