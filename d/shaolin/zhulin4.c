// Room: /d/shaolin/zhulin4.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
����һ����ʯ�̳ɵ�С�����������۵�ͨ��ǰ������������
�ܵ����֡������˼�������Ω�����ߵ��·�棬��ɮ��ľ������
΢�紵����Ҷ�������������������˳���Ϊ֮һ�ӣ����Ǿ���
���������ڡ�
LONG );
	set("exits", ([
		"east" : __DIR__"hsyuan4",
		"north" : __DIR__"zhulin5",
		"south" : __DIR__"zoulang5",
	]));
	set("outdoors", "shaolin");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

