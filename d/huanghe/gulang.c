// Room: /huanghe/gulang.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
���˳ǽ������ܣ��������䣬�������ں����������ˡ�����������
������ëƤ��ɢ�أ������������Ƥ����һ�����żҿڣ���һ��������
�����ˣ����˹�����������ʮ������ˮ�Ӽ������ݡ�
LONG );
	set("exits", ([
		"south"     : __DIR__"yongdeng",
		"north"     : __DIR__"xueguan",
		"east"      : __DIR__"yaocaidian",
		"west"      : __DIR__"xiaojiaqiao",
		"northeast" : __DIR__"dacaigou",
	]));
	set("objects", ([
		"/d/taishan/npc/dao-ke" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

