// Room: /city2/xichang2.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����ڽ��ϣ��е�����Ľ���Ҫ�ȱ𴦵ĸɾ������ࡣ����������
�����ţ�ֱͨ�����⡣�����ǿյ����Ľֵ����ϱ���һ������ϡ�ٵ�С
�����ͨ��������
LONG );
        set("outdoors", "city2");
	set("no_clean_up", 0);
	set("exits", ([
		"east" : __DIR__"xichang1",
		"south" : __DIR__"alley1",
		"west" : __DIR__"ximen",
		"north" : __DIR__"xidan",
	]));
	setup();
	replace_program(ROOM);
}

