// Room: /d/taohuacun/taohua1.c

inherit ROOM;

void create()
{
	set("short", "�һ���");
	set("long", @LONG
����һƬ�������һ��֣���ɽ��Ұ������֦�ϣ������Һ����
�����һ���ͷ��������ϸϸ���˵Ĳ��ʼ�į���۷䡣������һ����
��Ҳ��խ���ּ�С�������������ܴԴԵ��۲ݺ����涷�޵�С����
LONG );
	set("outdoors", "city");
//	set("no_clean_up", 0);

	set("exits", ([
		"north" : __DIR__"taohua2",
		"south" : "/d/city/ximen",
	]));
	set("objects", ([
		"/d/wudang/npc/bee" : 1,
	]));
	setup();
	replace_program(ROOM);
}

