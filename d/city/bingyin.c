// Room: /city/bingyin.c
// YZC 1995/12/04 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��Ӫ");
	set("long", @LONG
�����Ǳ�Ӫ���������鵽�����ǹٱ����е����佫��ָ�����жӲ�����
�еĶ������������е����š�����������Ϣ����ǽ��������˧��������ɫ
��Ѱ�������ܡ����������������ȫ�������Χ�˹��������ƿ�����̫�
�ϱ���һ����(men)��
LONG );
	set("item_desc", ([
		"men" : "����һ�ȼ�������š�\n",
	]));
	set("exits", ([
		"south" : __DIR__"bingqiku",
		"north" : __DIR__"bingyindamen",
	]));
	set("objects", ([
		__DIR__"npc/shi" : 1,
		__DIR__"npc/wujiang" : 2,
		__DIR__"npc/bing" : 2,
	]));
//	set("no_clean_up", 0);
	create_door("south", "����", "north", DOOR_CLOSED);
	setup();
}
int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
		dir == "south")
		return notify_fail("�ٱ���ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}

