// road9.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
��������ˣ����У���˽Σ�����������ϲ�������������
����������������ߡ������ڴ�������ϱߡ��ϱ�������һ�������
LONG);
        set("exits", ([
            "west"      : __DIR__"road8",
            "south"     : __DIR__"road10",
            "southwest" : __DIR__"duanqiao",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
