// Room: /d/fuzhou/wuyishan3.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "���η�");
	set("long", @LONG
���η�Ϊ���ĵ�һʤ�أ�ɽ�ƶ��ͣ�ʯ����ɽ���䣬��Ϊ��
����ɽ��ΡȻ�������Ƕ�Զ��������ɽȫ�������۵ס�ֻ������
��Ůңң������ĬĬ���顣
LONG );
	set("exits", ([
		"southdown" : __DIR__"wuyishan5",
	]));
	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

