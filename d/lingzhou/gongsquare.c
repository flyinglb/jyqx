// Room: /lingzhou/gongsquare.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ʹ��㳡");
	set("long", @LONG
�����ǻʹ��㳡��
LONG );
	set("exits", ([
		"south"  : __DIR__"gonggate",
	]));
	set("objects", ([
		__DIR__"npc/gongweishi" :2,
	]));
	setup();
	create_door("south" , "���Ṭ��", "north" , DOOR_CLOSED);
}

