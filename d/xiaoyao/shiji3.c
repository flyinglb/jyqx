// shiji3.c
// by shilling 97.2

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ�����ϱ�������չ��ʯ������������ȱ�������������е�������
�ĸо��������Ǹ����ε�ͭ�ţ������Ǹ�ʯ�ҡ�
LONG );
	set("exits", ([
		"south" : __DIR__"shishi2",
		"north" : __DIR__"tongmen",
	]));
	create_door("south", "ʯ��", "north", DOOR_CLOSED);
	set("no_clean_up", 0);
	setup();
}
