// road10.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
�غ�����Ե������������ֹ��ӣ������۴��αȣ���������������
һƬ̫ƽ���־��󡣽ֵĶ�����һ����¥��
LONG);
        set("exits", ([
            "north"     : __DIR__"road9",
            "south"     : __DIR__"road11",
            "east"      : __DIR__"jiulou",
            "west"      : __DIR__"marryroom",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
