// Room: /huanghe/huanghe_1.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ƺ�");
	set("long", @LONG
�ƺ����ɹŸ�ԭ�ϱ������ʣ���̫��ɽ������������תͷ���£�
�γɽ��µķֽ硣������������и��ɿڡ�
LONG );
	set("exits", ([
		"south"     : __DIR__"weifen",
		"west"      : __DIR__"hetao",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

