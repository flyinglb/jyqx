// Room: /d/quanzhou/bamboo.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�������ͥ");
	set("long", @LONG
����һƬ���ܵ����֡������˼�������Ω�����ߵ��·�棬��ɮ
��ľ������΢�紵����Ҷ�������������������˳���Ϊ֮һ�ӣ�
���Ǿ��ѵ��������ڡ�
LONG );
	set("exits", ([
		"east" : __DIR__"qinglong",
	]));
	set("objects",([
		"/clone/food/jiudai" : 1,
//                "/d/baituo/npc/tong-ren" : 4,
		"/clone/food/jitui"  : 3,
	]));
//	set("no_clean_up", 1);
	set("sleep_room", 1);
	setup();
	replace_program(ROOM);
}

