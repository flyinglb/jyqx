// Room: /lingzhou/caodi1.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�������ݸ������ڵأ���ɫ����ƽʱ�������ţ���ǰ�ĸ��������
������û����ɵ�����ˮ���վ�š������и���ġ�
LONG );
	set("exits", ([
		"south" : __DIR__"dongdajie",
	]));
	set("objects", ([
		"/d/city/npc/yayi" : 4,
	]));
	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	setup();
	replace_program(ROOM);
}

