// Room: /d/shaolin/shijie4.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
ˮ��Խ��Խ��ɽ�������ŨŨ��ˮ����ʯ���ϣ����ѵ�ɽ
϶�У�������һ����ϸϸ��Ȫˮ�����һ�ɳα̵�СϪ����ɽ��
������ȥ����Χ���⵴���������������������ɾ���
LONG );
	set("exits", ([
		"northup" : __DIR__"shijie5",
		"eastdown" : __DIR__"shijie3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}

