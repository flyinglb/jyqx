// Room: /d/shaolin/zhonglou5.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "��¥���");
	set("long", @LONG
һ����ȥ��ֻ��������ƣ���ɽ���У����˽�����֮����
��Ϊһһɨ������ǰ�����������¥�����������¾����۵ס�
��������������������һƬ�񺣡�������Χ��ȫ�µ�������
���ѵ����֣�һ���������ߡ�
LONG );
	set("exits", ([
		"up" : __DIR__"zhonglou6",
		"down" : __DIR__"zhonglou4",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

