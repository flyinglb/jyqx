// Room: /city/caizhu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
һ�������ûʵĴ�լԺ�����������ǰ����ͷ�ߴ��ʯʨ����ס�˴�����
�࣬���������������������Ϲ�������������д�š��ޡ��֡��޼��ǵ���
�׸����������������ơ������ǹ�������������˹�����
LONG );
	set("exits", ([
		"south" : __DIR__"xidajie2",
		"north" : __DIR__"dayuan",
	]));
	set("objects", ([
		__DIR__"npc/wolfdog" : 2,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

