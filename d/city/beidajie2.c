// Room: /city/beidajie2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣�����Ǳ�����ͨ����⡣
�ϱ��Եúܷ�æ��������һ�������¥�󣬹��š�̫���ŷ硱����������
��������һ�����ң�������¥�����ֲ�������������������ѧʿ���ֱʡ�
���������������㴹�����Ρ�������һ�����ӵ����������ƣ��Ǿ�
������ѧ��֮������ͬ�����������ˡ�
LONG );
        set("outdoors", "city");
	set("exits", ([
		"east"  : __DIR__"zuixianlou",
		"south" : __DIR__"beidajie1",
		"west"  : __DIR__"wumiao",
		"north" : __DIR__"beimen",
	]));
        set("objects", ([
		"/d/npc/guojing": 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

