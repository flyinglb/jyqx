// Room: /d/city/jiaowai6.c
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
        "east" : __DIR__"jiaowai5",
        "west" : __DIR__"jiaowai7",
    ]));
    set("objects", ([
        CLASS_D("gaibang")+"/kuai-huosan" : 1,
        __DIR__"obj/shitou": 2,
    ]));
//    set("no_clean_up", 0);
    set("outdoors", "yangzhou");
    setup();
    replace_program(ROOM);
}
