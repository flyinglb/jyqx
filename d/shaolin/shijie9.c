// Room: /d/shaolin/shijie9.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
��ǰ��Ȼ����һ��Ƭ���֡����ֳ��ü��ܣ�ʯ���������˺�
�����Ƶ����롣���ڽ��£���������������һֻС����֨��
����ǰ��������ʧ���ֺ��
LONG );
	set("exits", ([
		"southdown" : __DIR__"shijie8",
		"northup" : __DIR__"shijie10",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}

