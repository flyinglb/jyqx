// Room: /city2/nandaj2.c

inherit ROOM;

void create()
{
	set("short", "�ϴ�ֹ㳡");
	set("long", @LONG
������һ�����ֵĹ㳡�����Ǳ������������֡������ҵĵضΡ�
һ�����ź�綫�����������ӻ������Ϸ���ܽ����������˵Ⱦ۾�
�����ڡ������Ĵ�����ϱ���ͷ���졣�ϱ��������ţ�ͨ������;
�������ϴ�֣�ͨ���찲�š������������ġ�������ݡ������Ƕ�
�����Ƕ���Ϣ���졣������һ�Һܴ�����׳�����ʱ������������
������
LONG );
        set("outdoors", "city2");
	set("exits", ([
		"west" : __DIR__"tuzai",
		"south" : __DIR__"yongding",
		"east" : __DIR__"chaguan",
		"north" : __DIR__"nandaj1",
	]));
        set("objects", ([
		"/d/baituo/npc/snaker" : 1,
		"/d/taishan/npc/dao-ke" : 1,
		"/d/taishan/npc/jian-ke" : 1,
        ]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

