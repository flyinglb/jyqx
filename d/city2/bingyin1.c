
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��Ӫ");
	set("long", @LONG
�����Ǳ�Ӫ���������鵽�����ǹٱ����е����佫��ָ�����жӲ�����
�еĶ������������е����š�����������Ϣ������Щ̫�����Ĵ��߶�����
����һ������(door)��
LONG );
	set("exits", ([
		"south" : __DIR__"bingqiku",
		"north" : __DIR__"dongchangdamen",
	]));
	set("item_desc", ([
		"door" : "����һ�ȼ�������š�\n",
	]));
	set("objects", ([
		"/d/huanggon/npc/taijian" : 1,
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	create_door("south", "����", "north", DOOR_CLOSED);
//	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
		dir == "south")
		return notify_fail("�ٱ���ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}

