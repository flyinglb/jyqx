
// Room: /d/songshan/taishique.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "̫����");
	set("long", @LONG
��ɽ�ųƷ��⣬�ֳƳ�ɽ��Ϊ�����е���������̫�����Ҷ�ɽ��
����ɡ������ʱ�� "�Ը�" ��ȡ��ʫ�� "����ά�ߣ���������" ��
������֮Ϊ����С���졣�׸����࣬����� "����̫������" ���֣�
׭�Ĺ��ӣ��Ծ���������������ȥ����ɽ�����µ�·����һ�����
���������ˡ�
LONG );
	set("exits", ([
		"north" : __DIR__"tianzhongge",
		"east"  : "/d/shaolin/ruzhou",
		"west"  : "/d/shaolin/shijie1",
	]));
	set("outdoors", "songshan");
	set("objects", ([
		__DIR__"npc/yao" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

