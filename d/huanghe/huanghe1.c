// Room: /huanghe/huanghe1.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ƺӰ���");
	set("long", @LONG
�����ǻƺӰ��ߡ��ƺ����ʵ�����Ѿ���ɳ�����ˡ���ɫ�ĺ�ˮ
�ںӴ��﷭���ţ������ţ�����һ�����޴�����ѡ������и�կ�ӡ�
LONG );
	set("exits", ([
		"south" : __DIR__"tiandi4",
		"north" : __DIR__"weifen",
		"east"  : __DIR__"huanghe2",
		"west"  : __DIR__"huanghegate",
	]));
	set("objects", ([
		__DIR__"npc/hou" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

