// Room: /d/shaolin/andao1.c
// Date: YZC 96/02/06

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��������ʪ�ĵص����ı��ôֲڵ�Ƭ���ݶ���ɣ�һ
�ſ�ˮ������ǽ�ڹ����������ڵ��ϡ�Ҳ������Ϊ��ʱ������ͨ
�е�Ե�ʣ������ص�������һ�ɸ�ʬ��Ķ����
LONG );
	set("exits", ([
		"south" : __DIR__"rukou",
		"north" : __DIR__"jianyu1",
	]));
	create_door("north","ľ��","south",DOOR_CLOSED);
	set("objects",([
		__DIR__"npc/ad-laoshu" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
}

