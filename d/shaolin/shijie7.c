// Room: /d/shaolin/shijie7.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
ʯ�������������죬�ٲ��ڽ���Խ��ԽС��ˮ��Ҳ����Զȥ
��λ���Żһ�ɫɮ�µ�ɮ�˲����������������ɽ��ʱ��Ų���
�ȣ������Ǹ�����ӡ�����Զ�����ƺ����Կ���ʯ��һ�ǡ�
LONG );
	set("exits", ([
		"southdown" : __DIR__"shijie6",
		"east" : __DIR__"shanmen",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}

