// Room: /d/city/jiaowai8.c
// Jan. 8.1998 by Venus
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "�ݵ�");
    set("long", @LONG
�������ݽ����һƬ���ݵأ���Ӣ�ͷף������裬��¶
Ϧ�⣬������Ƣ�������ѿ�����������ʱ��
LONG );
    set("exits", ([
        "east" : __DIR__"nanmen",
        "west" : __DIR__"jiaowai9",
    ]));
    set("no_clean_up", 0);
    set("outdoors", "yangzhou");
    setup();
    replace_program(ROOM);
}
