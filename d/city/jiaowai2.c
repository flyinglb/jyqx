// Room: /d/city/jiaowai2.c
// Jan. 8.1998 by Venus
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "����");
    set("long", @LONG
���ݽ�������֣���֦ͦ�Σ���ľ��б���ּ�С��������
��Զ�����в������֣�������ת��ʹ���ʱ���⾡����
    �������˺ܶ���֦ʯ�顣
LONG );
    set("exits", ([
        "north" : __DIR__"jiaowai1",
        "south" : __DIR__"jiaowai3",
    ]));
    set("objects", ([
        CLASS_D("gaibang")+"/qiu-wanjia": 1,
        __DIR__"obj/shuzhi": 1,
        __DIR__"obj/shitou": 1,
    ]));
//    set("no_clean_up", 0);
    set("outdoors", "yangzhou");
    setup();
    replace_program(ROOM);
}
