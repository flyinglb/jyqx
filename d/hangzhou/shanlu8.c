// shanlu8.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
ɽ����ľï�ܣ������������ﻹ���������ɡ������߱㵽�˻�������
�ϱ�������ɽ��·��
LONG);
        set("exits", ([
            "south"     : __DIR__"road7",
            "north"     : __DIR__"huanglongdong",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
