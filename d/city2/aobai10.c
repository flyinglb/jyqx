
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
����һ����������רΪ���ݴ�����ֱ�ӵ������õġ�
�ϱ���һ��ľ��(door)��
LONG );
	set("exits", ([
		"south" :  __DIR__"aobai6",
		"northeast" : __DIR__"aobai11",
	]));
	set("item_desc", ([
		"door" : "����һ�ȼ����ľ�š�\n",
	]));
	create_door("south", "ľ��", "north", DOOR_CLOSED);
	set("no_clean_up", 0);
	setup();
}
