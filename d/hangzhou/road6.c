// road6.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
��������ˣ����У���˽Σ�����������ϲ�������������
������������������ߡ��ϱ���ͨ���յ̡�������������
LONG);
        set("exits", ([
            "north"     : __DIR__"yuelang",
            "south"     : __DIR__"suti1",
            "west"      : __DIR__"road5",
            "east"      : __DIR__"road7",
        ]));
        set("objects" , ([
            __DIR__"npc/liumang" :4,
            __DIR__"npc/liumangtou" :1,
        ]));
        set("outdoors", "hangzhou");
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
