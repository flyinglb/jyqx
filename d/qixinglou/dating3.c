#include <room.h>
inherit ROOM;

void create()
{
    set("short","����");
    set("long",@LONG
��������¥���õ���¥,�������������������һ�����ȣ���֪��ͨ������
���Ǳ������ˣ���·�����ˡ�
LONG
    );
    set("sleep_room","1");
    set("exits",([
        "west" : __DIR__"chang",
        "east" : __DIR__"chang2",
        "north" : __DIR__"chang3",
        "down"  : __DIR__"dating2",
    ]));
    set("no_kill",1);
    set("no_fight",1);
    set("no_hit",1);
    set("steal",1);
    setup();
}
