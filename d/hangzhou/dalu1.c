// dalu1.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��·");
        set("long", @LONG
·�Ķ�����һ��Сɽ��ɽ�������дУ�����������ɽ�ϱ���һ��
���������ĺõط�����ȴ��������ռΪ˽�С���·�򶫱��������졣
LONG);
        set("exits", ([
            "northeast" : __DIR__"dadao2",
            "south"     : __DIR__"dadao3",
        ]));
        set("objects", ([
            __DIR__"npc/tiao-fu": 1,
            __DIR__"npc/honghua1" : 2,
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
}
