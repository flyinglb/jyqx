// Room: /city/dongdajie2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ڶ�����ϣ����ż�ʵ����ʯ����档�����Ƕ����ţ�����������
�ǹٱ���ߺ���������������ʵĶ�����������һ�𡣱�����һ�����ֺŵ�ҩ
�̣��ϱ��Ǵ����̣�����������������Զ����������
LONG );
        set("outdoors", "city");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"dongmen",
		"south" : __DIR__"datiepu",
		"west"  : __DIR__"dongdajie1",
		"north" : __DIR__"yaopu",
	]));
        set("objects", ([
                "/d/npc/xiaofeng": 1,
	]));

	setup();
	replace_program(ROOM);
}

