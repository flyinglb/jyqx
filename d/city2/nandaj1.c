// Room: /city/nandajie1.c

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�������ϴ�֡��������찲�Ź㳡���ϱ����ϴ�ֹ㳡��������
һ�ҵ��̣�ǽ��д��һ�����ġ������֣���ϸ��������������ѹ��
���ּۻ��۵�������������һ��С�͵ꡣ
LONG );
        set("outdoors", "city");
	set("exits", ([
		"west" : __DIR__"dangpu",
		"south" : __DIR__"nandaj2",
		"east" : __DIR__"kedian",
		"north" : __DIR__"tian_anm",
	]));
        set("objects", ([
		"/d/shaolin/npc/tiao-fu" : 1,
		"/d/city2/npc/xiaofan" : 1,
        ]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

