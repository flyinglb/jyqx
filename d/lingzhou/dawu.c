// Room: /lingzhou/dawu.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "���д���");
	set("long", @LONG
����һ��ԭľ�Ƴɵ�����ߴ���������ȥ����Щ���µ��Լ����
�����ײ�����������ľ�ܿգ�һ��ľ��ͨ���¥����¥��¥���Ϲ���һ
������һ�������Ĵ��죬����ȥ���ƾɲ���������ֻ֪���������
LONG );
	set("exits", ([
		"out"     : __DIR__"kongdi",
	]));
	set("objects", ([
		__DIR__"npc/ye" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

