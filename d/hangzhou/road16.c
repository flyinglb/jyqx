// road16.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
��������ˣ����У���˽Σ�����������ϲ�������������
�������߿����׷壬�ϱ��Ǿ����¡�
LONG);
        set("exits", ([
            "northup" : __DIR__"xizhaoshan",
            "south"   : __DIR__"jingcisi",
            "east"    : __DIR__"road15",
            "west"    : __DIR__"road20",
        ]));
        set("objects", ([
            __DIR__"npc/baizhen" : 1,
        ]));
        set("outdoors", "hangzhou");
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
