// Room: /d/mingjiao/sushe.c
// Jan.5 1997 by Venus

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "��������");
    set("long", @LONG
�߽�������ᣬ��Ŀ�����������Ž����ƺ���������㡣����
���ﲻͨ����Ҳ�����ڴ˶�����
LONG );
    set("exits", ([
        "out" : __DIR__"mjleimen1",
    ]));
    set("no_clean_up", 0);
    set("sleep_room", 1);
    set("no_fight", 1);
    setup();
    replace_program(ROOM);
}
