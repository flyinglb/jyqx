// Room: /d/shaolin/shijie5.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
һ�Ҿ޴���ٲ������������Խɽ�䣬ˮ����Ũ�÷·����
����ˮ�������ɽ�ͼ����𱡱����������۲�ɢ��������ˮ��
���������ʯ��������ˮ�գ�����ȥ���ÿ������˴������
LONG );
	set("exits", ([
		"southdown" : __DIR__"shijie4",
		"northup" : __DIR__"shijie6",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}

