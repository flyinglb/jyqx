// Room: /d/shaolin/zhulin6.c
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
		"east" : __DIR__"hsyuan6",
		"south" : __DIR__"zhulin5",
                "north" : __DIR__"zhulin10",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}

