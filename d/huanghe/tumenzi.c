// Room: /huanghe/tumenzi.c
// Java Sep. 22 1998

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������Ҳ����ǰפ���ĵط�����Χȫ��ɳĮ���м�һ��СС�����ޣ�
���������е��ص������ס������ǰ��������һ������ռ������������
��Ϊ��Ӫ�ĳ����ӣ��޶�����
LONG );
	set("exits", ([
		"south"     : __DIR__"wuwei",
		"northeast" : __DIR__"shixiazi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

