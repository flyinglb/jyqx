// Room: /huanghe/qingcheng.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "���");
	set("long", @LONG
���λ�ھ�Զ�������ٶ�ʮ����ϰ�ʮ��������ݣ���Ϊ��ǣ�
��ʵֻ�Ǹ�С����Ϊ�ش���ȥ���ĵ�Ҫ�壬����������ĺʹ��ε���
�ö����뾭����������������������֡�
LONG );
	set("exits", ([
		"north" : __DIR__"shamo",
		"east"  : __DIR__"hetao",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

