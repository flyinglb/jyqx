// Room: /city2/aobai5.c


inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
һ���ţ�һ�������˱Ƕ�����Ѭ����ֱ����ˮ����̨���������̣�
һ���ʷ����ֵļһ����ڳ���,һ����������ʦ��
LONG );
	set("exits", ([
		"south" : __DIR__"aobai3",
	]));
	set("objects", ([
		__DIR__"npc/chushi" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

