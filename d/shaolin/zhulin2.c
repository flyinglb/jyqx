// Room: /d/shaolin/zhulin2.c
// Date: YZC 96/01/19

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
����һ����ʯ�̳ɵ�С�����������۵�ͨ��ǰ������������
�ܵ����֡������˼�������Ω�����ߵ��·�棬��ɮ��ľ������
΢�紵����Ҷ�������������������˳���Ϊ֮һ�ӣ����Ǿ���
���������ڡ�
LONG );
	set("exits", ([
		"east" : __DIR__"wuqiku",
		"west" : __DIR__"hsyuan2",
		"south" : __DIR__"zhulin1",
		"north" : __DIR__"zhulin3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	create_door("east","ľ��","west",DOOR_CLOSED);
	setup();
}

