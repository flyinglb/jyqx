#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short","���Ƹ�");
    set("long",@LONG
�����ǰϺ���ķ���,ֻ��ǽ�Ϲ�����������:����ƽ,������ʲô��ƽ��һ��
������һ����һ������������Ů����˵�����ĳ�������!

LONG
    );
    set("sleep_room","1");
    set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"liangong7",
        "southeast" : __DIR__"chang4",
    ]));
    set("no_fight",1);
    set("no_sleep_room",1);
    set("no_steal",1);
    set("no_beg",1);
    setup();
}
