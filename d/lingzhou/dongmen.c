// Room: /lingzhou/dongmen.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "���ݶ���");
	set("long", @LONG
���Ƕ����ţ��������Ϸ����ż����������֡���ǽ�����ż��Źٸ�
��ʾ��һ��·������ͨ�����һƬ���֡�
LONG );
	set("exits", ([
		"west"      : __DIR__"dongdajie",
		"northeast" : __DIR__"luorilin1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	setup();
	replace_program(ROOM);
}

