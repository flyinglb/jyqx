// Room: /d/quanzhou/zahuopu.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
������һ��ר��Ů���õĶ�����С���ӡ�
LONG );
	set("exits", ([
		"east" : __DIR__"xijie",
	]));
	set("objects", ([
		__DIR__"npc/chen" : 1,
	]) );
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

