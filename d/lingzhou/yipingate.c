// Room: /lingzhou/yipingate.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "һƷ�ô���");
	set("long", @LONG
����������һƷ�õ����ڵأ�����������ֵı��棬��һ���ߴ��
ʯͷ����������ȥ���֮�����ſ���������ʿվ�ţ��Ȳ��ߴ�Ҳ���뺷��
�ͻʹ��ſڵ�������Զ�������Ǻ����ſڵ����۱�Ҳ���в��磬������
�����յ��������㲻�ѿ����������������ĸ��֣�˭��֪����һƷ��
�������¸���Ϊ����Ч����
LONG );
	set("exits", ([
		"north"  : __DIR__"yipindayuan",
		"south"  : __DIR__"xidajie",
	]));
	set("objects", ([
		__DIR__"npc/yipinwushi" : 2,
	]));
	setup();
        create_door("north" , "ͭƤ����", "south" , DOOR_CLOSED);
}

int valid_leave(object me, string dir)
{
        if (dir == "north" && 
            !(int)me->query("yipin/joined") && 
            objectp(present("wu shi", environment(me))))
           return notify_fail("һƷ����ʿ��ס���ȥ·��\n");

        return ::valid_leave(me, dir);
}

