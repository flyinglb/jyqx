// Room: /lingzhou/nandajie.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�����������ϴ�֣�Ҳ����ҵ����ĵضΣ�һ����ȥֻ��������
����������������ɫ�ĵ��к��������������ҫ�·�����������������
���ǲ��٣�������һ�Ҿƹݣ�������һ�ҳ���ꡣ
LONG );
	set("exits", ([
		"south" : __DIR__"nanmen",
		"north" : __DIR__"center",
		"east"  : __DIR__"chema",
		"west"  : __DIR__"jiuguan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	setup();
	replace_program(ROOM);
}

