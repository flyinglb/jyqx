// Room: /city/xidajie2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������������ϣ��е�����Ľ���Ҫ�ȱ𴦵ĸɾ������ࡣ�����Ϊ����
���š���Ӫ���ܱ�����Ե�ʣ������Ƕ�ϲ��ס��������߾����ĵ�û�м���
���ˣ�������������ͨ�����⡣�ϱ���һ����ݣ�������һ�������ûʵĴ�լ
Ժ��
LONG );
        set("outdoors", "city");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"xidajie1",
		"south" : __DIR__"wuguan",
		"west"  : __DIR__"ximen",
		"north" : __DIR__"caizhu",
	]));

        set("objects", ([
                "/d/quanzhen/npc/youfang": 1,
		"/d/npc/duanyanqing.c":1,
	]));

	setup();
	replace_program(ROOM);
}

