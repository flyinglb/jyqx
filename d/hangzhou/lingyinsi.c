// lingyinsi.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���������������£���ǰ���峺��СϪ��Ϫ�Խ�����Ȫͤ�ͺ���
ͤ���������Ŀ�ɼ����������������������ϱ�ص������
LONG);
        set("exits", ([
                "enter"     : __DIR__"tianwangdian",
                "south"     : __DIR__"road1",
        ]));
        set("objects",([
            __DIR__"npc/seng": 1,
        ]));
        set("outdoors", "hangzhou");
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
