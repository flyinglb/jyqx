// Room: /d/mingjiao/mjtianmen.c
// Jan.5 1997 By Venus

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "������");
    set("long", @LONG
����һƬ�����أ���ɳ���𣬽�â��գ���ǹ���գ�ɱ��
ӯҰ������С���Ӱ����Բ��һ��̴��������ޡ����˵أ�
���ܸо������̰��������ĸ��ܷ��顣
LONG );
    set("exits", ([
        "northwest" : __DIR__"mjtianmen1",
        "southeast" : __DIR__"mjsimen1",
    ]));
    set("objects", ([
        "/d/shaolin/npc/mu-ren": 5,
    ]));
    set("outdoors", "mingjiao");
    setup();
    replace_program(ROOM);
}
