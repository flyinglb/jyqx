// Room: /lingzhou/jiangjungate.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�󽫾���");
	set("long", @LONG
�����������󽫾����������ĸ��ڣ��ڶ���ֵ����У����������
�š�һɫ���ܴ��ݣ�����Уξ����ȥ�뺷���£��˿����������ֵĿ���
�䵶������ǰ��
LONG );
	set("exits", ([
		"north"  : __DIR__"dongdajie",
		"south"  : __DIR__"jiangjunyuan",
	]));
	set("no_fight",1);
	set("objects", ([
		__DIR__"npc/xiaowei" : 2,
	]));
	setup();
        create_door("south" , "��ľ����", "north" , DOOR_CLOSED);
}

int valid_leave(object me, string dir)
{
        if (dir == "south" && 
            objectp(present("xiao wei", environment(me))))
           return notify_fail("Уξ��ס�����ȥ·���󽫾����ڸ��ϣ�\n");

        return ::valid_leave(me, dir);
}

