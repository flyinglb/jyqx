// Room: /d/shaolin/shijie8.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
���￴���ǰ�ɽ���ˡ���Զ��ǰ����һ��Сʯͤ����λ�ο�
������ЪϢ��ɽ·��������ʮ��ƽ̹�����ߵ�ɽ������������
�˼������µ�ʫ�䡣Զ��ɽ�ּ���͵��֣���Ŀ�δ䡣
LONG );
	set("exits", ([
		"westdown" : __DIR__"shanmen",
		"northup" : __DIR__"shijie9",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}

