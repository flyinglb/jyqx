// Room: /lingzhou/gonggate.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ʹ�����");
	set("long", @LONG
����������Ļʹ����ţ����ȿ����������ţ��������ȭͷ���
ͭ�����ŵ�����վ�������¼���������ʿ���䱸���ϡ�
LONG );
	set("exits", ([
		"north"  : __DIR__"gongsquare",
		"south"  : __DIR__"beidajie",
	]));
	set("no_fight",1);
	set("objects", ([
		__DIR__"npc/gongweishi" : 2,
	]));
	setup();
        create_door("north" , "���Ṭ��", "south" , DOOR_CLOSED);
}

int valid_leave(object me, string dir)
{
        if (dir == "north" && 
            objectp(present("wei shi", environment(me))))
           return notify_fail("��ʿ������һ�����������ǲ������ܽ�ȥ�ĵط���\n");

        return ::valid_leave(me, dir);
}

