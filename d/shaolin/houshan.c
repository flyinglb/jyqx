// Room: /d/shaolin/houshan.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "СԺ");
	set("long", @LONG
��վ�����м������ǰ�������ƺ����ñ��ص�ɽ���������ģ�
��ʵ������ˮ���ݶ���é���̵ģ�����¶���������紵�����ƶ���
��ߵ����Ӻ����Ǽ����ᣬ�ұߵ������ű߹��ż���ɹ�ɵ�������
���м����ݵ����ǿ��ŵġ�
LONG );
	set("exits", ([
		"east" : __DIR__"xiaojing2",
		"north" : __DIR__"xiaowu",
		"northeast" : __DIR__"chufang2",
		"northwest" : __DIR__"zhushe",
	]));
	set("outdoors", "shaolin");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

