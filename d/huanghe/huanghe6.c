// Room: /huanghe/huanghe6.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ƺӰ���");
	set("long", @LONG
�����ǻƺӰ��ߡ��ƺ����ʵ�����Ӵ���������ɫ�ĺ�ˮ�ھ���
������ȥ��ʹ������������ˮʱ�Ŀ�����
LONG );
	set("exits", ([
		"northeast" : __DIR__"huanghe7",
		"southwest" : __DIR__"huanghe5",
	]));
	set("objects", ([
		__DIR__"npc/zu" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

