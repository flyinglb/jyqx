// /guanwai/xiaowu.c

inherit ROOM;

void create()
{
	set("short", "Сé��");
	set("long", @LONG
����һ���ó���ɽ��ľ�ݳɵ�С�ݣ����ڴ�ɨ�ĺܸɾ������ܵ�ǽ����
��������Ƥ��ѩ����һ��СС����������һ��Ӣ�����ꡣ
LONG );
	set("exits", ([
		"south" : __DIR__"baihe",
	]));
	set("objects", ([
		__DIR__"npc/hufei" : 1,
	]));
	set("no_beg", "1");
	set("no_fight", "1");
//	set("no_clean_up", 0);
//	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}

