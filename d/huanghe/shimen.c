// Room: /huanghe/shimen.c
// Java Sep. 22 1998

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
������ʯ�ţ������ĵĲ�ʯ��������û�б�������ֻ�б�صİ���
ʯ���������������ʯ�ذ��������������İ���ʯ�̳ɵġ�ʱ���д���
�Ŀ������ٸ������������û��ûҹ�Ŀ��ɰ���ʯ������˵��º��û
����վ������������һ������
LONG );
	set("exits", ([
		"northwest" : __DIR__"yinpanshui",
		"south"     : __DIR__"hongshanxia",
		"north"     : __DIR__"wufosi",
	]));
	set("objects", ([
		__DIR__"npc/xixiabing" : 1,
		__DIR__"npc/caishiren" : 2,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

