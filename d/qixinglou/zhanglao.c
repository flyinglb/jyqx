#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short","�����");
    set("long",@LONG
�����Ĵ���֮һ����ˮ���µľ��ң�ʲô��û�У����������̫�󣬺�Ϳ�˰ɣ�

LONG
    );
    set("sleep_room","1");
    set("exits", ([ /* sizeof() == 2 */
        "south" : __DIR__"liangong3",
        "northwest" : __DIR__"chang2",
    ]));
    set("no_fight",1);
    set("no_sleep_room",1);
    set("no_steal",1);
    set("no_beg",1);
    setup();
}
