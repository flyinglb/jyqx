// Room: /d/city/jiaowai4.c
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
        "north"     : __DIR__"jiaowai3",
        "west"      : __DIR__"jiaowai5",
        "southeast" : "/d/guiyun/shulin1",
    ]));
    set("objects", ([
        CLASS_D("gaibang")+"/zhao-gouer" : 1,
        __DIR__"obj/shuzhi": 2,
        __DIR__"obj/shitou": 2,
    ]));
//    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}

