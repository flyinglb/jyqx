// Room: /d/hengshan/baiyunan.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������Ǻ�ɽ�������˵ľ��������ڹ�����¹�������������
һ�����ţ��ı���Ȼ����ɽ�����𽭺���û�뵽���־�Ȼ����һ��
��˹��
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "south"  : __DIR__"square",
        ]));
	set("objects", ([
		__DIR__"npc/xian" : 1,
		__DIR__"npc/zheng" : 1,
		__DIR__"npc/qin" : 1,
	]));
//      set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
        "/clone/board/hengshan_b"->foo();
}

