// Room: /lingzhou/yinfang.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "Ӫ��");
	set("long", @LONG
����������Ӫ��Ӫ����һ����ľ��ɷ������, �ſڿյ�����ʿ
��Χ�ɸ�Ȧ�����֣����ľ��г����������������Ӣ�ۣ�ʿ��������
�Ǳ��δ󺺡�
LONG );
	set("exits", ([
		"south" : __DIR__"biaoqiyin",
	]));
	set("objects", ([
		__DIR__"npc/xixiabing" :3,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	setup();
	replace_program(ROOM);
}

