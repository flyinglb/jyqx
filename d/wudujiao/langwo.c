// by mayue

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������е�һ����������������ζ�˱ǣ��洦���ǳ�ʣ��
�޹ǡ���ֻ�ݵ�Ƥ����ͷ�Ķ��������Ӿ����ƺ�Ҫ��ȥ��ʳ�ˡ�
LONG
	);
//      set("outdoors", "wudujiao");

	set("exits", ([
//		"east" : __DIR__"langwo",
//		"south" : __DIR__"milin5",
		"out" : __DIR__"milin4",
//		"north" : __DIR__"milin3",
	]));
        set("objects", ([
                __DIR__"npc/wolf1": 2,
                __DIR__"npc/wolf2": 1,
	]));

	setup();
	replace_program(ROOM);
}

