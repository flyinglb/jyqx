// road1.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
����ϼ�������������������Ϸ�������ο͡����߹���СϪ��
���������ˡ��ϱ����Ϸ������·��
LONG);
        set("exits", ([
                "northwest" : "/d/quanzhou/jxnanmen",
                "northeast" : __DIR__"road2",
                "north"     : __DIR__"lingyinsi",
                "south"     : __DIR__"feilaifeng",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
