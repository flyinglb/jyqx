// Room: /huanghe/wufosi.c
// Java Sep. 22 1998

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������������Χȫ��ɳ������������Ѿ���������
���п������ɳ����ң��Ӱ���Ľ���������ϡ���Ա���������¡���
���֣�Ψһ���������Ľ����Ǵ����ݶ���ȫ�ǿ�����ǿ���������紵
�����������ġ���---��---������
LONG );
	set("exits", ([
		"south"     : __DIR__"shimen",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

