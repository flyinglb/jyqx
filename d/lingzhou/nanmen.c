// Room: /lingzhou/nanmen.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "��������");
	set("long", @LONG
�����ϳ��ţ��������Ϸ��̵��м����������֡���ǽ�����ż��Ź�
����ʾ��һ����·����ͨ�����̲��
LONG );
	set("exits", ([
		"south" : __DIR__"huangyangtan",
		"north" : __DIR__"nandajie",
	]));
	set("objects", ([
		__DIR__"npc/xiaowei" : 1,
		__DIR__"npc/xixiabing" : 2,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	setup();
	replace_program(ROOM);
}

