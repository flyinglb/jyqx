// road11.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
�غ�����Ե������������ֹ��ӣ������۴��αȣ���������������
һƬ̫ƽ���־��󡣽ֶ��ߵ�һ�ҵ����ﴫ�����������Ĵ�������
LONG);
        set("exits", ([
            "north"     : __DIR__"road10",
            "south"     : __DIR__"road12",
            "east"      : __DIR__"tiejiangpu",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
