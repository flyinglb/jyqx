#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short","�����");
    set("long",@LONG
�����Ĵ���֮һ���ϸ����ֵľ��ҡ�

LONG
    );
    set("sleep_room","1");
    set("exits", ([ /* sizeof() == 2 */
        "east" : __DIR__"liangong5",
        "west" : __DIR__"chang3",
    ]));
    set("no_fight",1);
    set("no_sleep_room",1);
    set("no_steal",1);
    set("no_beg",1);
    setup();
}
