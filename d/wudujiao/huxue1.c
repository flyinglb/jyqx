// by mayue


inherit ROOM;

void create()
{
	set("short", "��Ѩ");
	set("long", @LONG
�����Ǹ���������������Ҷ���������ζ�˱ǣ��洦���ǳ�ʣ��
�޹ǡ���ֻ�������ݵĴ��ϻ������ڶ���������ɹ̫����
LONG
	);
//      set("outdoors", "wudujiao");

	set("exits", ([
//		"east" : __DIR__"langwo",
		"south" : __DIR__"huxue2",
		"out" : __DIR__"milin7",
//		"north" : __DIR__"milin3",
	]));
        set("objects", ([
                __DIR__"npc/laohu": 2,
	]));

	setup();
	replace_program(ROOM);
}

