// Room: /huanghe/tiandi2.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "���");
	set("long", @LONG
������ľ����ϡ�裬��Զ����һЩ��ׯ�������������𡣴�ׯ��Χ
��һ������أ�������һЩ���ڸ�����ũ�ˡ�
LONG );
	set("exits", ([
		"southwest" : __DIR__"shulin5",
		"east"      : __DIR__"tiandi1",
	]));
	set("objects", ([
		"/d/wudang/npc/cow" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

