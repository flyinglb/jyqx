// Room: /huanghe/tiandi3.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "���");
	set("long", @LONG
������һ��Ƭũ���Զ����һЩ��ׯ�������������𡣴�ׯ��Χ
��һ������أ�������һЩ���ڸ�����ũ�ˡ�
LONG );
	set("exits", ([
		"west"      : __DIR__"tiandi1",
		"northeast" : __DIR__"tiandi4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

