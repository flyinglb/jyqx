// gbandao.c ������
// by aji
#include <room.h>

inherit ROOM;

void kick();

void create()
{
        set("short", "����");
        set("long", @LONG
һ����խ�ĵ�������ͨ������ֱ�ĳ��������졣ͨ���ľ�ͷ��������
����͸������
LONG );
        set("exits", ([
		"east" : __DIR__"gbxiaowu",
                "out" : __DIR__"pomiao",
        ]));
	set("objects",([
		CLASS_D("gaibang") + "/jian" : 1
	]));
//	set("no_clean_up", 0);
	create_door("out", "С��", "enter", DOOR_CLOSED);

        setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "ؤ��") && dir == "east" &&
                objectp(present("jian zhanglao", environment(me))))
                return notify_fail("����һ�Ѿ�ס�������˵�������š�\n");
        return ::valid_leave(me, dir);
}

