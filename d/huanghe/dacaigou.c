// Room: /huanghe/dacaigou.c
// Java Sep. 22 1998

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
��񹵵��Ʋ���������������Ҫ���Ƚ�ƽ̹���ٵ�����ȫ�����֣�
ʱ�����Է򿳲�����������д�����
LONG );
	set("exits", ([
		"southwest" : __DIR__"gulang",
		"north"     : __DIR__"wuqiao",
	]));
	set("objects", ([
		__DIR__"npc/qiaofu" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

