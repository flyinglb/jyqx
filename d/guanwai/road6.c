// /guanwai/road6.c
inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������һ����ʯ�̳ɵĴ���ϣ����������ű�ֱͨ��İ�������������
������ȥ��ȫ���ޱ��޼ʵ���Ұ����ߴ��·��м����Ͱ������꣬Ϊƽ̹��
��������˼�����͵����ߡ�·�Ͻ����ĳ�����һЩ��ѩ��
LONG );
	set("exits", ([
		"north" : __DIR__"road7",
		"south" : __DIR__"road5",
	]));
	set("objects",([
		__DIR__"npc/sanhu" : 1,
	]));
//	set("no_clean_up", 0);
 	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}

