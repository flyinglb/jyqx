// Room: /lingzhou/yipinzhang.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "һƷ���ʷ�");
	set("long", @LONG
����������һƷ�õ��ʷ�����Ը����һƷ�õĽ������֣���������
��������һ������������һĨ���ڴ˹��ʡ�
LONG );
	set("exits", ([
		"east"  : __DIR__"yipindayuan",
	]));
	set("objects", ([
		__DIR__"npc/zhangfang" :1,
	]));
	setup();
	replace_program(ROOM);
}

