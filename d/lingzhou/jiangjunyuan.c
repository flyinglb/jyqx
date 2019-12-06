// Room: /lingzhou/jiangjunyuan.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "��������Ժ");
	set("long", @LONG
�����ǽ������Ĵ�Ժ������һ�¿����İ����ձڣ����顰���ı�����
�ĸ����֣�����ǵ������Ļʵ���Ԫ껡�һɫ����ש�̵أ��м�������
����Ժ����ɨ����������լ���������ʷ��������Ǹ�СԺ��
LONG );
	set("exits", ([
		"east"  : __DIR__"xiaoyuan",
		"west"  : __DIR__"zhangfang",
		"enter" : __DIR__"neizai",
		"north" : __DIR__"jiangjungate",
	]));
	set("no_fight",1);
	set("objects", ([
		"/d/city/npc/jiading" : 2,
	]));
	setup();
	create_door("north" , "��ľ����", "south" , DOOR_CLOSED);
//	create_door("south" , "������", "north" , DOOR_CLOSED);
}

int valid_leave(object me, string dir)
{
        if (dir == "south" && 
            objectp(present("xiao wei", environment(me))))
           return notify_fail("Уξ��ס�����ȥ·���󽫾����ڸ��ϣ�\n");

        return ::valid_leave(me, dir);
}

