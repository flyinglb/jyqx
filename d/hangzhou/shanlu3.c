// shanlu3.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
СϪ���ɽ·����Ϫ��һ��Сʯ�š�Ϫ��ũ��С������Ϸ���֡�                    
���ϱ㵽�������á����¾��������á�
LONG);
        set("exits", ([
            "southup"   : __DIR__"faxisi",
            "northdown" : __DIR__"fajinsi",
        ]));
        set("objects", ([
            __DIR__"npc/boy" : 3,
        ]));
        set("outdoors", "hangzhou");
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
