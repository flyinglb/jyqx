// Room: /huanghe/guangchang.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�㳡");
	set("long", @LONG
�㳡ռ�����󣬲����Ͻ���������ȥ�ɴ�ƺӰ�ġ�����������
��Χ����Щ���ᣬ�����ھ�ס��
LONG );
	set("exits", ([
		"east"  : __DIR__"huanghegate",
		"west"  : __DIR__"xiayiting",
	]));
	set("objects", ([
		__DIR__"npc/wu" : 1,
		__DIR__"npc/qian" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

