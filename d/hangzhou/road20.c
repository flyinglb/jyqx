// road20.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
��������ˣ����У���˽Σ�����������ϲ�������������
����������������ߣ��������յ̡�
LONG);
        set("exits", ([
            "north"     : __DIR__"suti7",
            "west"      : __DIR__"road19",
            "east"      : __DIR__"road16",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
