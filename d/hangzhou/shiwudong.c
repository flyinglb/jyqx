// shiwudong.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ʯ�ݶ�");
        set("long", @LONG
ɽ·����ʯ�ݶ���ʯ�ݶ��������ж������������������ߴ����
�ྻ�������Ͽ���խ��״�縡�ݡ����ϱ㵽������¤��ɽ·�ľ�ͷ����
һ���ɱ����ϵĴ����
LONG);
        set("exits", ([
                "westup"    : __DIR__"manjuelong",
                "east"      : __DIR__"road18",
        ]));
        set("objects", ([
            __DIR__"npc/xiezi": 1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

