// Room: /d/shaolin/shijie3.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
ʯ���������ƺ���ÿ�����Щ�����µ�ɽ���������������
�����Ϊһˬ��Զ����������ˮ�������н�Զ��ɽ���Ϲ���
�˺��ܵ����ܣ��������ҡ߮��
LONG );
	set("exits", ([
		"southdown" : __DIR__"shijie2",
		"westup" : __DIR__"shijie4",
	]));
	set("objects",([
		__DIR__"npc/xiao-hai" : 1,
	]));
	set("outdoors", "shaolin");
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

