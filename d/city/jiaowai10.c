// Room: /d/city/jiaowai10.c
// Jan. 8.1998 by Venus
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "����");
    set("long", @LONG
���ݽ����ï�����֣���ɭ�ɲ���̧ͷ�������ա�����Ҳ
�����������������ĵط��������߳��ε����
LONG );
    set("exits", ([
        "east"  : __DIR__"jiaowai9",
        "west"  : __DIR__"jiaowai11",
        "north" : __DIR__"jiaowai12",
    ]));
    set("objects", ([
        CLASS_D("gaibang")+"/jiang-sy" : 1,
        __DIR__"obj/shuzhi": 2,
        __DIR__"obj/shitou": 1,
    ]));
//    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}
