// by mayue

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
����һ�����ϵĻ��������Զ����Լ����һƬ���̵�ɽ�͡�
·��������ϡ����������·Խ��Խխ����Щ�ط���������һ
ƬƬ���Ӳݡ������ƺ���һ����·��
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
		"southeast" : __DIR__"xiaolu",
		"south" : __DIR__"shanlu1",
//		"west" : __DIR__"wumiao",
		"north" : __DIR__"road2",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));

	setup();
	replace_program(ROOM);
}

