// /guanwai/road8.c
inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������һ����ʯ�̳ɵĴ���ϡ����ܵ���Ұ�Ѿ�����ѩ���ǣ�������ȥ
�����Լ��Ѿ��������ޱ��޼ʵ�ѩԭ�С���������ѩ����Х������������
�����������������ƺ���һ�ƴ�������
LONG );
	set("exits", ([
		"north" : __DIR__"muqiao",
		"south" : __DIR__"road7",
	]));
	set("no_clean_up", 0);
 	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}

