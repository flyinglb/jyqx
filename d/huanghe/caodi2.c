// Room: /huanghe/caodi2.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
������һ��������Ĳݵأ�����һ����ɫ��̺�����ڵ��ϡ��ݴ���
����һЩ��֪����С�����к�ġ��Ƶģ������ϵġ������ϡ���Ҷ�ϵ�
¶�����ž�Ө�Ĺ⡣
LONG );
	set("exits", ([
                "enter" : "/d/qixinglou/qixinglou",
		"east" : __DIR__"caodi1",
		"west" : __DIR__"shulin1",
	]));
	set("objects", ([
		"/d/hangzhou/obj/eluanshi" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

